/*******************************************************************
 *   File Type          :       api declaration
 *   Implementor        :       jhpark
 *   Create Date        :
 *   Description        :
 *   Modification history
 *   date                    modification
 --------------------------------------------------------------------
 ********************************************************************/

#include "PetraAPILCallTest.h"
#include "PetraRowRef.hpp"

struct petra_row_ref_t {
    PetraRowRef* rows;
    int err_code;
    char* err_buffer;
    int err_buffer_size;
};

static void setException(petra_row_ref_t* row_ref, int err_code, const char* err_string) {
    if (!row_ref) return;
    int err_string_len = strlen(err_string);
    if (err_string && row_ref->err_buffer_size < err_string_len) {
        delete row_ref->err_buffer;
        row_ref->err_buffer_size = err_string_len + 128;
        row_ref->err_buffer = new char[row_ref->err_buffer_size];
    }
    memset(row_ref->err_buffer,0,row_ref->err_buffer_size);
    strcpy(row_ref->err_buffer,err_string);
}

petra_row_ref_t* PetraAPIL_PetraRowRef_new(const char* table_name, int table_name_len, uint32_t num_rows)
{
printf("call PetraAPIL_PetraRowRef_new -- start\n");
    petra_row_ref_t* row_ref = new petra_row_ref_t;
    if (!table_name) return NULL;
printf("call PetraAPIL_PetraRowRef_new -- 1 table_name[%s]\n",table_name);

    if (table_name_len == 0) table_name_len = strlen(table_name);
    char tname[33];
    strncpy(tname,table_name,table_name_len>32?32:table_name_len);
    tname[table_name_len] = 0;
    row_ref->rows = new PetraRowRef(tname,num_rows);
    row_ref->err_code = 0;
    row_ref->err_buffer = new char[128];
    row_ref->err_buffer_size = 128;
printf("call PetraAPIL_PetraRowRef_new -- end\n");
    return row_ref;
}

void PetraAPIL_PetraRowRef_delete(petra_row_ref_t* row_ref)
{
printf("call PetraAPIL_PetraRowRef_delete\n");    
    if (!row_ref) return;
    if (row_ref->rows) delete row_ref->rows;
    if (row_ref->err_buffer) delete row_ref->err_buffer;

    memset(row_ref,0,sizeof(petra_row_ref_t));

    delete row_ref;
}

const char* PetraAPIL_PetraRowRef_tableName(petra_row_ref_t* row_ref)
{
    if (!row_ref) return NULL;
    if (!row_ref->rows) return NULL;

    return row_ref->rows->tableName();
}

int PetraAPIL_PetraRowRef_rowSize(petra_row_ref_t* row_ref)
{
    if (!row_ref) return 0;
    if (!row_ref->rows) return 0;
    int row_size = row_ref->rows->rowSize();
    if (row_size <= 0) {
        setException(row_ref,-100,"invalid row size.");
    }
    return row_size;
}

void PetraAPIL_PetraRowRef_rewind(petra_row_ref_t* row_ref)
{
    if (!row_ref) return;
    if (!row_ref->rows) return;

    row_ref->rows->rewind();
}

bool PetraAPIL_PetraRowRef_next(petra_row_ref_t* row_ref)
{
    if (!row_ref) return false;
    if (!row_ref->rows) {
        setException(row_ref,-100,"rows is not allocated.");
        return false;
    }

    return row_ref->rows->next();
}

uint8_t* PetraAPIL_PetraRowRef_data(petra_row_ref_t* row_ref)
{
    if (!row_ref) return NULL;
    if (!row_ref->rows) return NULL;

    st_petra_row* row_data = row_ref->rows->data();

    if (!row_data) {
        setException(row_ref,-200,"no data found.");
        return NULL;
    }
    
    return (uint8_t*)row_data;
}
