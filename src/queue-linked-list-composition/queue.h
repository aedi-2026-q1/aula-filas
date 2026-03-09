#ifndef QUEUE_H
#define QUEUE_H

#include "inc/element.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct Queue Queue;

Queue* queue_create();
void queue_destroy(Queue* queue);
void queue_enqueue(Queue* queue, Element element);
Element queue_dequeue(Queue* queue);
Element queue_front(Queue* queue);
Element queue_back(Queue* queue);
size_t queue_size(Queue* queue);
bool queue_is_empty(Queue* queue);
void queue_print(Queue* queue);

#endif