CC = clang -Wall 

BUILD_DIR = build

all: main

dir:
	mkdir -p $(BUILD_DIR)

element: dir
	$(CC) -c inc/element.c -o $(BUILD_DIR)/element.o

linked_list: element
	$(CC) -c inc/linked_list.c -o $(BUILD_DIR)/linked_list.o

queue: linked_list
	$(CC) -c queue.c -o $(BUILD_DIR)/queue.o

main: queue
	$(CC) main.c $(BUILD_DIR)/queue.o $(BUILD_DIR)/linked_list.o $(BUILD_DIR)/element.o -o $(BUILD_DIR)/main


clean:
	rm -rf $(BUILD_DIR)

.PHONY: all dir element linked_list queue main clean
