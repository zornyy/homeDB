#ifndef HOMEDB_STORE_H
#define HOMEDB_STORE_H

#include "../data/data.h"

int storeData( rawData *data );

rawData createRawData( void* data, size_t size );

#endif // HOMEDB_STORE_H
