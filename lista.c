#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void set_variable(struct list* l, const char* key, int value) {
    struct node* current = l->first;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    // Se não encontrou, cria nova variável
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strncpy(new_node->key, key, sizeof(new_node->key));
    new_node->value = value;
    new_node->next = l->first;
    l->first = new_node;
}

int get_variable(struct list* l, const char* key, int* found) {
    struct node* current = l->first;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            *found = 1;
            return current->value;
        }
        current = current->next;
    }
    *found = 0;
    return 0;
}
