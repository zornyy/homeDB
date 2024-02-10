#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./store.h"
#include "../data/data.h"


rawData createRawData( void* data, size_t size ) {
  rawData binary;
  binary.data = malloc( size );
  if ( binary.data == NULL ) {
    printf("Memory allocation failed");
    binary.data = 0;
    return binary;
  } 
  memcpy( binary.data, data, size );
  binary.size = size;
  return binary;
}

int storeData( rawData *data ) {
  FILE *file = fopen( "./homedb_data/data.bin", "ab" );
  if ( file == NULL ) {
    printf( " File could not be opened" );
    return -1;
  }

  size_t dataWritten = fwrite( data, sizeof( data ), 1, file );

  if ( dataWritten != 1 ) {
    printf( "Failed to write data to binary" );
    return -1;
  }

  fclose( file );
  return 0;
}

