#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#include "./src/store/store.h"
#include "./src/data/data.h"

#define MAX_QUERY_LENGTH 256

bool isFile( char* filename ) {
  if (access(filename, F_OK) == 0) {
    return true;
  } else {
    return false;
  }
}

int main( int argc, char* argv[] ) {
  
  // Create data folder if needed
  char* fname = "homedb_data";
  if ( isFile( fname ) ) {
    printf( "Data directory was already existing\n" );
  } else { 
    int status = mkdir( fname, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH );
    if ( status == 0 ) {
      printf( "Data directory has been created\n" );
    } else {
      printf( "Data directory could not be created\n" );
      return 1;
    }
  }

  
  // Program main loop
  // Note that the query input is handled in the server only for dev phase
  bool running = true;
  char userQuery[MAX_QUERY_LENGTH];
  while ( running ) {
    // Get user query
    if ( fgets( userQuery, sizeof( userQuery ), stdin ) ) {
        userQuery[strcspn(userQuery, "\n")] = '\0';
    } else {
      printf( "Failed to read your query properly" );
    }
    // Check for special queries
    if ( strcmp(userQuery, "exit" ) == 0 )  {
      printf( "Database instance closed\n" );
      running = false;
    } else {
      // process & execute query

      // Fake query execution
      char dataToStore[] = "This is the data to store.";
      int testInt = 10;
      rawData myData;
      myData = createRawData( &testInt, sizeof( testInt ) );
      
      if ( myData.data == 0 ) {
        return -1;
      }

      storeData( &myData );
    }
  }


  

  return 0;
}
