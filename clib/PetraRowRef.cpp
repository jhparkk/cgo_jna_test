/*****************************************************************************
 *   File Type          : class definition
 *   Classes            : PetraCallTest
 *   Implementor        : jhpark
 *   Create Date        : 
 *   Description        :
 *   Modification history
 *
 *   date         modification
 *---------------------------------------------------------------------------
 *****************************************************************************/
#include "PetraRowRef.hpp"
#include <time.h>

PetraRowRef::PetraRowRef(const char* table_name, uint32_t num_rows /* default 1000 */)
    : num_rows_(num_rows)
{
    memset(table_name_,0,33);
    strncpy(table_name_,table_name,strlen(table_name)>32?32:strlen(table_name));
    rows_ = new st_petra_row*[num_rows_];
    for (int i=0; i<num_rows_; i++) {
        rows_[i] = new st_petra_row;
        st_petra_row* row = rows_[i];
        row->id = i;
        time_t ct = time(&ct);
        row->last_update = (uint32_t)ct;
        row->status = 1;
        row->ref_id = i;
        memset(row->ref_name,0,257);
        sprintf(row->ref_name,"ref_name_%d",i);     
        memset(row->reserved,0,33);
        sprintf(row->reserved,"reserved_%d",i);
    }

    curr_select_idx_ = -1;
}

PetraRowRef::~PetraRowRef()
{
    for (int i=0; i<num_rows_; i++) {
        if (rows_[i]) delete rows_[i];
        rows_[i] = 0;
    }
    delete rows_;
}

