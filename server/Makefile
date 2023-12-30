CC = gcc
BUILD_DIR = build

homedb_server: $(BUILD_DIR)/main.o $(BUILD_DIR)/data.o $(BUILD_DIR)/store.o $(BUILD_DIR)/retrieve.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/data.o $(BUILD_DIR)/store.o $(BUILD_DIR)/retrieve.o -o $(BUILD_DIR)/homedb

$(BUILD_DIR)/main.o: main.c 
	$(CC) -c main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/data.o: ./src/data/data.c ./src/data/data.h
	$(CC) -c ./src/data/data.c -o $(BUILD_DIR)/data.o

$(BUILD_DIR)/store.o: ./src/store/store.c ./src/store/store.h
	$(CC) -c ./src/store/store.c -o $(BUILD_DIR)/store.o

$(BUILD_DIR)/retrieve.o: ./src/retrieve/retrieve.c ./src/retrieve/retrieve.h
	$(CC) -c ./src/retrieve/retrieve.c -o $(BUILD_DIR)/retrieve.o

clean:
	rm -rf build/* 
