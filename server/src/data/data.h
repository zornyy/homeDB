#ifndef HOMEDB_DATA_H
#define HOMEDB_DATA_H

#include <time.h>

// Creating storable data types

typedef struct {
  time_t timestamp;
  int value;
} int_record;

typedef struct {
  time_t timestamp;
  char value[256];
} str_record;

typedef struct {
  time_t timestamp;
  double value; // Temperatures are stored as kelvins
} temp_record;


#endif // HOMEDB_STORE_H
