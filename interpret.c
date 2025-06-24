#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "interpret.h"

void interpret(const char *source, Stack *s) {
    char op[10];
    char arg[10];

    sscanf(source, "%s %s", op, arg);

    if (strcmp(op, "push") == 0) {
        int value = atoi(arg);
        stack_push(s, value);  
        printf("Valor %d empilhado.\n", value);
    } else if (strcmp(op, "add") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a + b);  
        printf("Soma: %d\n", a + b);
    } else if (strcmp(op, "sub") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a - b);  
        printf("Subtracao: %d\n", a - b);
    } else if (strcmp(op, "mul") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a * b); 
        printf("Multiplicacao: %d\n", a * b);
    } else if (strcmp(op, "div") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (b != 0) {
            stack_push(s, a / b);  
            printf("Divisao: %d\n", a / b);
        } else {
            printf("Erro: Divisão por zero!\n");
        }
    } else if (strcmp(op, "print") == 0) {
        int value = stack_pop(s);  
        printf("Valor desempilhado: %d\n", value);
    } else {
        printf("Comando desconhecido: %s\n", op);
    }
}
