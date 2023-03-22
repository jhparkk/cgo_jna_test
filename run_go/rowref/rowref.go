package rowref

/*
#cgo CFLAGS: -I./ -g -Wall -Wno-unused-variable
#cgo LDFLAGS: -L../ -lpetracalltest
#include <stdio.h>
#include <stdlib.h>
#include "PetraAPILCallTest.h"

struct st_petra_row {
  int64_t id;
  uint32_t last_update;
  uint16_t status;
  int64_t ref_id;
  char ref_name[257];
  char reserved[33];
};
typedef struct st_petra_row st_petra_row;

st_petra_row* convStPetraRow(uint8_t* data) {
	return (st_petra_row*)data;
}
*/
import "C"
import "unsafe"

type StPetraRow struct {
	ID         int64
	LastUpdate uint32
	Status     uint16
	RefID      int64
	RefName    string
	Reserved   string
}

func (s *C.struct_st_petra_row) Unmarshal(d *StPetraRow) {
	d.ID = int64(s.id)
	d.LastUpdate = uint32(s.last_update)
	d.Status = uint16(s.status)
	d.RefID = int64(s.ref_id)
	d.RefName = C.GoString(&s.ref_name[0])
	d.Reserved = C.GoString(&s.reserved[0])
}

type PetraRowRef struct {
	ref *C.petra_row_ref_t
	row StPetraRow
}

func New(tableName string, numRows int) *PetraRowRef {
	r := new(PetraRowRef)
	byteTableName := []byte(tableName)
	tl := len(tableName)
	r.ref = C.PetraAPIL_PetraRowRef_new((*C.char)(unsafe.Pointer(&byteTableName[0])), C.int(tl), C.uint(numRows))
	return r
}

func (r *PetraRowRef) Delete() {
	C.PetraAPIL_PetraRowRef_delete(r.ref)
}

func (r *PetraRowRef) GetTableName() string {
	ctn := C.PetraAPIL_PetraRowRef_tableName(r.ref)
	tn := C.GoString(ctn)
	return tn
}

func (r *PetraRowRef) GetRowSize() int {
	crs := C.PetraAPIL_PetraRowRef_rowSize(r.ref)
	rs := int(crs)
	return rs
}

func (r *PetraRowRef) Rewind() {
	C.PetraAPIL_PetraRowRef_rewind(r.ref)
}

func (r *PetraRowRef) Next() bool {
	return bool(C.PetraAPIL_PetraRowRef_next(r.ref))
}

func (r *PetraRowRef) Data() *StPetraRow {
	s := C.convStPetraRow(C.PetraAPIL_PetraRowRef_data(r.ref))
	s.Unmarshal(&r.row)

	return &r.row
}
