
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../clib/PetraAPILCallTest.h"

struct st_petra_row {
  int64_t id;
  uint32_t last_update;
  uint16_t status;
  int64_t ref_id;
  char ref_name[257];
  char reserved[33];
};
typedef struct st_petra_row st_petra_row;

int main(int argc, char* argv[]) {
    printf("##start program\n");
    printf("\n");
    int loop_cnt = 10;
    int rownums = 1000000;

    if (argc > 1) {
        loop_cnt = strtol(argv[1],0,10);
    }

    const char* table_name = "test_table";
    int tlen = strlen(table_name);
	petra_row_ref_t* row_ref = PetraAPIL_PetraRowRef_new(table_name,tlen, rownums);

    printf("table name : %s \n", PetraAPIL_PetraRowRef_tableName(row_ref));
    printf("row size : %d \n", PetraAPIL_PetraRowRef_rowSize(row_ref));

    void (*rewind)(petra_row_ref_t*) = &PetraAPIL_PetraRowRef_rewind;
    bool (*next)(petra_row_ref_t*) = &PetraAPIL_PetraRowRef_next;
    uint8_t* (*data)(petra_row_ref_t*) = &PetraAPIL_PetraRowRef_data;


    st_petra_row* row = 0;
    uint32_t cnt = 0;
    for (int i=0; i<loop_cnt; i++) {
        (*rewind)(row_ref);
        while ((*next)(row_ref)) {
            row = (st_petra_row*)(*data)(row_ref);
            //printf("id[%ld] last_update[%u] status[%u] ref_id[%ld] ref_name[%s] reserved[%s]\n",row->id,row->last_update,row->status,row->ref_id,row->ref_name,row->reserved);
            cnt++;
     
        }
    }
    printf("\n1cnt[%u]\n",cnt);
    
    PetraAPIL_PetraRowRef_delete(row_ref);

    printf("\n");
    printf("##end program\n");

    return 0;
}