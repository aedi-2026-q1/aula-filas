#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

struct Queue {
    Element* elements;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
};

void queue_error(const char* message) {
    fprintf(stderr, "Queue error: %s\n", message);
}

Queue* queue_create(size_t capacity) {
    Queue* queue = malloc(sizeof(Queue));

    queue->elements = malloc(capacity * sizeof(Element));
    queue->front = 0;
    queue->back = 0;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

void queue_destroy(Queue* queue) {
    free(queue->elements);
    free(queue);
}

size_t queue_size(Queue* queue) {
    return queue->size;
}

bool queue_is_empty(Queue* queue) {
    return queue->size == 0;
}

bool queue_is_full(Queue* queue) {
    return queue->size == queue->capacity;
}

// TODO: implement the rest of the queue operations (enqueue, dequeue, front, back, print)