#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int *data;
    int top;
    int size;
} Stack;

Stack* new_stack(int size);
void stack_push(Stack* s, int value);
int stack_pop(Stack* s);
void stack_print(Stack* s);

#endif
