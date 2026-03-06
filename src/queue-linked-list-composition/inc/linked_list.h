#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "element.h"

#include <stddef.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insert_first(LinkedList* list, Element element);
void list_insert_last(LinkedList* list, Element element);
void list_insert_after(LinkedList* list, size_t position, Element element);
void list_remove_first(LinkedList* list);
void list_remove_last(LinkedList* list);
void list_remove_at(LinkedList* list, size_t position);
Element list_get_at(LinkedList* list, size_t position);
Element list_get_first(LinkedList* list);
Element list_get_last(LinkedList* list);
size_t list_size(LinkedList* list);
bool list_is_empty(LinkedList* list);
void list_print(LinkedList* list);

#endif