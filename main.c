#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "interpret.h"

static void repl(Stack *s) {
    char line[1024];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret(line, s);  
    }
}

int main() {
   
    Stack* s = new_stack(100);
    
    repl(s);

    free(s->data); 
    free(s);        

    return 0;
}
