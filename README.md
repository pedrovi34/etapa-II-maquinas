
## 🧮 Máquina de Pilha com Variáveis
ALUNO: PEDRO VICTOR ROCHA GONÇALVES
Este projeto implementa uma **máquina virtual baseada em pilha**, capaz de interpretar comandos matemáticos simples e manipular **variáveis nomeadas** usando uma **lista encadeada**.

---

### 📁 Estrutura do Projeto

```
maquina-pilha/
├── main.c             // Função principal e REPL (loop de leitura)
├── interpret.c        // Interpretador de comandos
├── interpret.h
├── stack.c            // Implementação da pilha
├── stack.h
├── lista.c            // Implementação da lista encadeada (variáveis)
├── lista.h
└── README.md          // Este arquivo
```

---

### ⚙️ Compilação

Compile usando `gcc` (ou outro compilador C compatível):

```bash
gcc -o maquina main.c interpret.c stack.c lista.c
```

---

### ▶️ Execução

Após compilar, execute com:

```bash
./maquina
```

---

### ⌨️ Comandos Suportados

#### `push <valor | nome_variável>`

* Se for número inteiro: empilha normalmente.
* Se for nome de variável: empilha valor da variável (se existir).

#### `pop <nome_variável>`

* Desempilha valor e armazena na variável informada.

#### `add`, `sub`, `mul`, `div`

* Operações aritméticas entre os dois valores no topo da pilha.

#### `print`

* Desempilha e imprime o valor do topo da pilha.

---

### 🧪 Exemplo de Sessão

```plaintext
> push 42
Valor 42 empilhado.
> push 5
Valor 5 empilhado.
> add
Resultado: 47
> push 8
Valor 8 empilhado.
> sub
Resultado: 39
> pop a
Valor 39 desempilhado e armazenado em 'a'.
> push 56
Valor 56 empilhado.
> push 8
Valor 8 empilhado.
> add
Resultado: 64
> pop b
Valor 64 desempilhado e armazenado em 'b'.
> push a
Variável 'a' empilhada com valor 39.
> push b
Variável 'b' empilhada com valor 64.
> add
Resultado: 103
> push 6
Valor 6 empilhado.
> add
Resultado: 109
> print
Valor: 109
```

---

### 🚨 Erros Tratados

* Pilha cheia ou vazia.
* Variável não encontrada.
* Divisão por zero.
* Comando inválido.
* Uso incorreto de argumentos.

---

### 🧼 Limpeza de Memória

A pilha e a lista encadeada são corretamente desalocadas ao final do programa.

---

### 📌 Requisitos

* Compilador C (`gcc`, `clang`, etc.)
* Sistema compatível com POSIX (Linux, macOS) ou Windows com terminal C.

