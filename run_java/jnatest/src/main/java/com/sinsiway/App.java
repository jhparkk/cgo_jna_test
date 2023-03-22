package com.sinsiway;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;
import com.sun.jna.Structure.FieldOrder;
import com.sun.jna.Pointer;

public class App 
{
    public interface PetraAPILCallTest extends Library
    {
/*
        public static class StPetraRow {
            public long id;
            public int lastUpdate;
            public short status;
            public long refId;
            public String refName;
            public String reserved;
            StPetraRow(Pointer ptr, int rowSize) {
                byte[] byteLong = new byte[8];
                byte[] byteInt =  new byte[4];
                byte[] byteShort =  new byte[2];

                int idx = 0;
                int length = 8;
                ptr.read(idx, byteLong, 0, length);
                this.id = ByteBuffer.wrap(byteLong).order(java.nio.ByteOrder.LITTLE_ENDIAN).getLong();
                idx += length;

                length = 4;
                ptr.read(idx, byteInt, 0, length);
                this.lastUpdate = ByteBuffer.wrap(byteInt).order(java.nio.ByteOrder.LITTLE_ENDIAN).getInt();
                idx += length;

                length = 2;
                ptr.read(idx, byteShort, 0, length);
                this.status = ByteBuffer.wrap(byteShort).order(java.nio.ByteOrder.LITTLE_ENDIAN).getShort();
                idx += length;

                length = 8;
                ptr.read(idx, byteLong, 0, length);
                this.refId = ByteBuffer.wrap(byteLong).order(java.nio.ByteOrder.LITTLE_ENDIAN).getLong();
                idx += length;

                length = 257;
                byte[] byteString = new byte[1024];
                ptr.read(idx, byteString, 0, length);
                this.refName = new String(byteString);

                length = 33;
                ptr.read(idx, byteString, 0, length);
                this.reserved = new String(byteString);
            }
        }
*/

        // struct st_petra_row {
        //     int64_t id;
        //     uint32_t last_update;
        //     uint16_t status;
        //     int64_t ref_id;
        //     char ref_name[257];
        //     char reserved[33];
        // };
        // typedef struct st_petra_row st_petra_row;
        @FieldOrder({"id","lastUpdate","status","refId","refName","reserved"})
        public static class StPetraRow extends Structure {
            public long id;
            public int lastUpdate;
            public short status;
            public long refId;
            public byte[] refName;
            public byte[] reserved;
            public StPetraRow(Pointer ptr) {
                super(ptr);
                refName = new byte[257];
                reserved = new byte[33];
                read();
            }
        }

        @FieldOrder({"rows","errCode","errBuffer","errBufferSize"})
        public static class PetraRowRef extends Structure {
            public static class ByReference extends PetraRowRef implements Structure.ByReference {}
            public Pointer rows;
            public int errCode;
            public String errBuffer;
            public int errBufferSize;
        }

        PetraAPILCallTest INSTANCE = (PetraAPILCallTest)Native.load("libpetracalltest", PetraAPILCallTest.class);

        PetraRowRef.ByReference PetraAPIL_PetraRowRef_new(String tname, int tsize, int numrows);
        void PetraAPIL_PetraRowRef_delete(PetraRowRef.ByReference rowRef);
        String PetraAPIL_PetraRowRef_tableName(PetraRowRef.ByReference rowRef);
        int PetraAPIL_PetraRowRef_rowSize(PetraRowRef.ByReference rowRef);
        void PetraAPIL_PetraRowRef_rewind(PetraRowRef.ByReference rowRef);
        boolean PetraAPIL_PetraRowRef_next(PetraRowRef.ByReference rowRef);
        Pointer PetraAPIL_PetraRowRef_data(PetraRowRef.ByReference rowRef);
    }

    static String byteArrayToHex(byte[] a) {
        StringBuilder sb = new StringBuilder();
        for(final byte b: a)
            sb.append(String.format("%02x ", b&0xff));
        return sb.toString();
    }

    public static void main( String[] args )
    {
        System.out.println( "#program start!" );
        System.out.println();

        PetraAPILCallTest lib = PetraAPILCallTest.INSTANCE;
        PetraAPILCallTest.PetraRowRef.ByReference r = new PetraAPILCallTest.PetraRowRef.ByReference();
        String tname = "test_table";
        int numrows = 1000;
        r = lib.PetraAPIL_PetraRowRef_new(tname,tname.length(),numrows);

        System.out.println("table name : " + lib.PetraAPIL_PetraRowRef_tableName(r));
        System.out.println("row size : " + lib.PetraAPIL_PetraRowRef_rowSize(r));

        lib.PetraAPIL_PetraRowRef_rewind(r);

        while (lib.PetraAPIL_PetraRowRef_next(r)) {
            final Pointer ptr = lib.PetraAPIL_PetraRowRef_data(r);
            if (ptr == null) {
                System.out.println("row not found.");
                continue;
            }
            
            // int rowSize = lib.PetraAPIL_PetraRowRef_rowSize(r);
            // byte[] bytes = new byte[rowSize];
            // ptr.read(0, bytes, 0, rowSize);
            // System.out.println(byteArrayToHex(bytes));

            PetraAPILCallTest.StPetraRow row = new PetraAPILCallTest.StPetraRow(ptr);
            //System.out.println(row);
            System.out.println("id["+row.id+"]" +" last_update["+row.lastUpdate+"]"+" status["+row.status+"]"+" ref_id["+row.refId+"]"+" ref_name["+new String(row.refName)+"]"+" reserved["+new String(row.reserved)+"]");
        }

        lib.PetraAPIL_PetraRowRef_delete(r);
        System.out.println();
        System.out.println( "#program end" );
    }
}
