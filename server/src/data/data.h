#ifndef HOMEDB_DATA_H
#define HOMEDB_DATA_H

#include <time.h>

// Creating storable data types

typedef struct {
  void* data;
  size_t size;
} rawData;

#endif // HOMEDB_STORE_H
