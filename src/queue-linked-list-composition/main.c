#include <stdio.h>

#include "queue.h"

void test_enqueue(void) {
    Queue* queue = queue_create();

    printf("Enqueueing 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, i + 1);
    }
    queue_print(queue);

    queue_destroy(queue);
}

void test_dequeue(void) {
    Queue* queue = queue_create();

    printf("Enqueueing 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, i + 1);
    }
    queue_print(queue);

    printf("Dequeueing all elements...\n");
    while (!queue_is_empty(queue)) {
        Element element = queue_dequeue(queue);
        printf("Dequeued: ");
        element_print(&element);
        printf("\n");
        queue_print(queue);
    }

    queue_destroy(queue);
}

int main(void) {
    printf("Testing enqueue...\n");
    test_enqueue();
    printf("Testing dequeue...\n");
    test_dequeue();
    return 0;
}