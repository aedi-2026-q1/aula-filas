#include "queue.h"
#include "inc/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * A queue implemented using a linked list. 
 * 
 * - implemented as composition (i.e., the queue contains a linked list)
 * - the queue operations are implemented using the linked list operations
 */

struct Queue {
    LinkedList* list;
};

void queue_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

Queue* queue_create() {
    Queue* queue = malloc(sizeof(Queue));

    queue->list = list_create();

    return queue;
}

void queue_destroy(Queue* queue) {
    list_destroy(queue->list);
    free(queue);
}

void queue_enqueue(Queue* queue, Element element) {
    list_insert_last(queue->list, element);
}

Element queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }

    Element res = list_get_first(queue->list);
    list_remove_first(queue->list);

    return res;
}

Element queue_front(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }

    return list_get_first(queue->list);
}

Element queue_back(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }

    return list_get_last(queue->list);
}

size_t queue_size(Queue* queue) {
    return list_size(queue->list);
}

bool queue_is_empty(Queue* queue) {
    return list_is_empty(queue->list);
}

void queue_print(Queue* queue) {
    list_print(queue->list);
}