/*******************************************************************
 *   File Type          :       api declaration
 *   Implementor        :       jhpark
 *   Create Date        :
 *   Description        :
 *   Modification history
 *   date                    modification
 --------------------------------------------------------------------
 ********************************************************************/
#ifndef PETRA_APIL_CALL_TEST_H_
#define PETRA_APIL_CALL_TEST_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct petra_row_ref_t petra_row_ref_t;

petra_row_ref_t* PetraAPIL_PetraRowRef_new(const char* table_name, int table_name_len, uint32_t num_rows);
void PetraAPIL_PetraRowRef_delete(petra_row_ref_t* row_ref);

const char* PetraAPIL_PetraRowRef_tableName(petra_row_ref_t* row_ref);
int PetraAPIL_PetraRowRef_rowSize(petra_row_ref_t* row_ref);
void PetraAPIL_PetraRowRef_rewind(petra_row_ref_t* row_ref);
bool PetraAPIL_PetraRowRef_next(petra_row_ref_t* row_ref);
uint8_t* PetraAPIL_PetraRowRef_data(petra_row_ref_t* row_ref);

#ifdef __cplusplus
}
#endif

#endif