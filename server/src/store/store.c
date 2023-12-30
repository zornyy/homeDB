#include <time.h>
#include <stdio.h>

#include "./store.h"
#include "../data/data.h"


int storeTemp( temp_record *record ) {
  FILE *file = fopen( "./homedb_data/data.bin", "ab" );
  if ( file == NULL ) {
    printf( "Could not open file" );
    return 1;
  }

  size_t dataWritten = fwrite( record, sizeof( temp_record ), 1, file );

  if ( dataWritten != 1 ) {
    printf( "Failed to write data to binary" );
    return 1;
  }

  fclose( file );

  return 0;
}

