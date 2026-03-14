#pragma once
#include "../functions/building_elements.h"
building_elements_in read_input(const char* filename);

void write_result(const char* filename, const stair_result& stair,
                  const RC_column_result& column);

