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

bool queue_enqueue(Queue* queue, Element element) {
    if (queue_is_full(queue)) {
        return false;
    }
    queue->elements[queue->back] = element;
    queue->back = (queue->back + 1) % queue->capacity;
    queue->size++;

    return true;
}

Element queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }

    Element element = queue->elements[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
}

Element queue_front(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }
    return queue->elements[queue->front];
}

Element queue_back(Queue* queue) {
    if (queue_is_empty(queue)) {
        queue_error("Empty queue");
        return element_null();
    }
    return queue->elements[(queue->back + queue->capacity - 1) % queue->capacity];
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

void queue_print(Queue* queue) {
    for (size_t i = 0; i < queue->size; i++) {
        element_print(queue->elements[(queue->front + i) % queue->capacity]);
        printf(" ");
    }
    printf("\n");
}