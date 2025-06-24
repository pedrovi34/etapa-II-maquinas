#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "lista.h"
#include "interpret.h"

static void repl(Stack* s, struct list* l) {
    char line[256];
    printf("Máquina de Pilha com Variáveis\n");
    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\nEncerrando.\n");
            break;
        }
        interpret(line, s, l);
    }
}

int main() {
    Stack* s = new_stack(100);
    struct list vars = { NULL };

    repl(s, &vars);

    free(s->data);
    free(s);
    return 0;
}
