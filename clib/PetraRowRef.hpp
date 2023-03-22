/*******************************************************************
 *   File Type          : class declaration
 *   Classes            : PetraRowRef
 *   Implementor        : jhpark
 *   Create Date        : 
 *   Description        :
 *   Modification history
 *
 *   date         modification
 --------------------------------------------------------------------
 ********************************************************************/
#ifndef PETRA_CALL_TEST_H_
#define PETRA_CALL_TEST_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct st_petra_row {
  int64_t id;
  uint32_t last_update;
  uint16_t status;
  int64_t ref_id;
  char ref_name[257];
  char reserved[33];
};
typedef struct st_petra_row st_petra_row;

class PetraRowRef {
public:
  PetraRowRef(const char* table_name, uint32_t num_rows=1000);
  ~PetraRowRef();

  const char* tableName() { return table_name_; }
  inline uint32_t rowSize() { return sizeof(st_petra_row); }
  inline void rewind() {
    curr_select_idx_ = -1;
  }
  inline bool next() {
    if (curr_select_idx_ < 0) {
      curr_select_idx_ = 0;
    } else if (curr_select_idx_ < num_rows_-1) {
      curr_select_idx_++;
    } else {
      // out of bound
      return false;
    }
    return true;
  }
  inline st_petra_row* data() {
    return rows_[curr_select_idx_];
  }
protected:
private:
  char table_name_[33];
  uint32_t num_rows_;
  st_petra_row** rows_;
  int32_t curr_select_idx_;
};

#endif