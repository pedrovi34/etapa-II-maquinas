#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* new_stack(int size) {
    Stack* s = malloc(sizeof(Stack));
    s->data = malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

void stack_push(Stack* s, int value) {
    if (s->top < s->size - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

int stack_pop(Stack* s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    } else {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
}

void stack_print(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
