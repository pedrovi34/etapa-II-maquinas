#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "lista.h"
#include "interpret.h"

int is_number(const char *str) {
    if (!str || *str == '\0') return 0;
    if (*str == '-' || *str == '+') str++;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void interpret(const char *source, Stack *s, struct list *l) {
    char op[20] = "", arg[20] = "";
    sscanf(source, "%s %s", op, arg);

    if (strcmp(op, "push") == 0) {
        if (is_number(arg)) {
            int value = atoi(arg);
            stack_push(s, value);
            printf("Valor %d empilhado.\n", value);
        } else if (strlen(arg) > 0) {
            int found = 0;
            int value = get_variable(l, arg, &found);
            if (found) {
                stack_push(s, value);
                printf("Variável '%s' empilhada com valor %d.\n", arg, value);
            } else {
                printf("Erro: Variável '%s' não encontrada.\n", arg);
            }
        } else {
            printf("Erro: 'push' requer argumento.\n");
        }
    } else if (strcmp(op, "pop") == 0) {
        if (strlen(arg) == 0) {
            printf("Erro: 'pop' requer o nome de uma variável.\n");
            return;
        }
        if (s->top >= 0) {
            int val = stack_pop(s);
            set_variable(l, arg, val);
            printf("Valor %d desempilhado e armazenado em '%s'.\n", val, arg);
        } else {
            printf("Erro: Pilha vazia!\n");
        }
    } else if (strcmp(op, "add") == 0 || strcmp(op, "sub") == 0 || strcmp(op, "mul") == 0 || strcmp(op, "div") == 0) {
        if (s->top < 1) {
            printf("Erro: '%s' requer dois valores.\n", op);
            return;
        }
        int b = stack_pop(s);
        int a = stack_pop(s);
        int result = 0;

        if (strcmp(op, "add") == 0) result = a + b;
        else if (strcmp(op, "sub") == 0) result = a - b;
        else if (strcmp(op, "mul") == 0) result = a * b;
        else if (strcmp(op, "div") == 0) {
            if (b == 0) {
                printf("Erro: Divisão por zero.\n");
                stack_push(s, a);
                stack_push(s, b);
                return;
            }
            result = a / b;
        }

        stack_push(s, result);
        printf("Resultado: %d\n", result);
    } else if (strcmp(op, "print") == 0) {
        if (s->top >= 0) {
            int val = stack_pop(s);
            printf("Valor: %d\n", val);
        } else {
            printf("Erro: Pilha vazia!\n");
        }
    } else if (strlen(op) > 0) {
        printf("Comando desconhecido: '%s'\n", op);
    }
}
