#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* first;
    Node* last;
    size_t size;
};

void list_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

bool list_is_position_valid(LinkedList* list, size_t position) {
    return position < list_size(list);
}

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;

}

void list_destroy(LinkedList* list) {
    Node* cur = list->first;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }

    free(list);
}

void list_insert_first(LinkedList* list, Element element) {
    Node* new_node = malloc(sizeof(Node));

    new_node->element = element;
    new_node->next = list->first;
    list->first = new_node;
    if (list->last == NULL) {
        list->last = new_node;
    }
    list->size++;
}

void list_insert_last(LinkedList *list, Element element) {
    Node* new_node = malloc(sizeof(Node));

    new_node->element = element;
    new_node->next = NULL;

    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->last->next = new_node;
        list->last = new_node;
    }
    list->size++;
}

void list_insert_after(LinkedList* list, size_t position, Element element) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
    } else {
        Node* cur = list->first;
        size_t i = 0;

        while (i < position) {
            cur = cur->next;
            i++;
        }

        Node* new_node = malloc(sizeof(Node));

        new_node->element = element;
        new_node->next = cur->next;
        cur->next = new_node;

        if (cur == list->last) {
            list->last = new_node;
        }
        list->size++;
    }
}

void list_remove_first(LinkedList* list) {
    if (list->first != NULL) {
        Node* trash = list->first;

        list->first = list->first->next;

        if (list->first == NULL) {
            list->last = NULL;
        }

        free(trash);
        list->size--;
    }
}

void list_remove_last(LinkedList* list) {
    if (list->first != NULL) {
        if (list->first == list->last) {
            free(list->first);
            list->first = NULL;
            list->last = NULL;
        } else {
            Node* cur = list->first;

            while (cur->next != list->last) {
                cur = cur->next;
            }

            Node* trash = list->last;

            list->last = cur;
            list->last->next = NULL;

            free(trash);
        }
        list->size--;
    }
}
void list_remove_at(LinkedList* list, size_t position) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
    } else if (position == 0) {
        list_remove_first(list);
    } else {
        Node* cur = list->first;
        size_t i = 0;

        while (i < position - 1) {
            cur = cur->next;
            i++;
        }

        Node* trash = cur->next;

        cur->next = trash->next;

        if (trash == list->last) {
            list->last = cur;
        }

        free(trash);
        list->size--;
    }
}

Element list_get_at(LinkedList* list, size_t position) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
        return element_null();
    } else {
        Node* cur = list->first;
        size_t i = 0;

        while (i < position) {
            cur = cur->next;
            i++;
        }

        return cur->element;
    }
}

Element list_get_first(LinkedList* list) {
    if (list_is_empty(list)) {
        list_error("Empty list");
        return element_null();
    }

    return list->first->element;
}

Element list_get_last(LinkedList* list) {
    if (list_is_empty(list)) {
        list_error("Empty list");
        return element_null();
    }

    return list->last->element;
}

size_t list_size(LinkedList* list) {
    return list->size;
}

bool list_is_empty(LinkedList* list) {
    return list->size == 0;
}

void list_print(LinkedList* list) {
    Node* cur = list->first;

    while (cur != NULL) {
        element_print(&cur->element);
        if (cur->next != NULL)
            printf(" -> ");
        cur = cur->next;
    }

    printf("\n");
}