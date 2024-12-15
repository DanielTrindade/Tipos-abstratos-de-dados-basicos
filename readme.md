# Estruturas de Dados em C - Lista, Fila e Pilha

## 📌 Índice
- [Sobre o Projeto](#sobre-o-projeto)
- [Estruturas Implementadas](#estruturas-implementadas)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Pré-requisitos](#pré-requisitos)
- [Instalação](#instalação)
- [Como Usar](#como-usar)
- [Complexidade das Operações](#complexidade-das-operações)
- [Licença](#licença)
- [Contato](#contato)
- [Referências](#referências)
- [Roadmap](#roadmap)

## 🎯 Sobre o Projeto
Este projeto implementa três estruturas de dados fundamentais em C, usando um design modular e orientado a reuso. O objetivo é fornecer uma implementação clara e eficiente para fins educacionais e práticos.

## 🚀 Estruturas Implementadas

### Lista Encadeada
Uma estrutura de dados linear e dinâmica que consiste em uma sequência de elementos onde:
- Cada elemento (nó) armazena um valor e um ponteiro para o próximo
- Suporta inserção e remoção em ambas as extremidades
- Mantém referências para o primeiro e último elementos
- Principal estrutura que serve de base para Fila e Pilha

**Principais operações:**
- `lst_criar()`: Cria uma nova lista vazia
- `lst_inserir_inicio()`: Insere no início
- `lst_inserir_fim()`: Insere no final
- `lst_remover_inicio()`: Remove do início
- `lst_remover_final()`: Remove do final

### Fila (Queue)
Uma estrutura que segue a política FIFO (First-In-First-Out), implementada através de lista encadeada onde:
- O primeiro elemento a entrar é o primeiro a sair
- Inserções ocorrem sempre no final (tail)
- Remoções ocorrem sempre no início (head)
- Ideal para processamento de dados em ordem de chegada

**Principais operações:**
- `fila_criar()`: Cria uma nova fila
- `fila_inserir()`: Insere no final da fila
- `fila_remover()`: Remove do início da fila
- `fila_vazia()`: Verifica se está vazia

### Pilha (Stack)
Uma estrutura que segue a política LIFO (Last-In-First-Out), implementada através de lista encadeada onde:
- O último elemento a entrar é o primeiro a sair
- Todas as operações ocorrem em uma extremidade (topo)
- Ideal para controle de chamadas de funções, expressões matemáticas

**Principais operações:**
- `pilha_criar()`: Cria uma nova pilha
- `pilha_push()`: Insere no topo
- `pilha_pop()`: Remove do topo
- `pilha_vazia()`: Verifica se está vazia

## 🛠️ Tecnologias Utilizadas
- Linguagem C (C11)
- GCC Compiler
- Make (opcional para build)
- Valgrind (para testes de memória)

## 📋 Pré-requisitos
- GCC 7.0 ou superior
- Make (opcional)
- Sistema operacional: Linux, macOS ou Windows (com WSL ou MinGW)

## 📥 Instalação

### Via Git
```bash
git clone https://github.com/DanielTrindade/Tipos-abstratos-de-dados-basicos.git
cd nome-do-repo
```

### Compilação Manual
```bash
gcc -c Lista.c Fila.c Pilha.c
gcc Lista.o Fila.o Pilha.o main.c -o programa
```

### Usando Make (opcional)
```bash
make all
```

## 💻 Como Usar

### Exemplo com Lista
```c
#include "Lista.h"

int main() {
    Lista *lst = lst_criar();
    lst_inserir_fim(lst, 10);
    lst_inserir_fim(lst, 20);
    lst_imprimir(lst);
    lst_limpar(lst);
    return 0;
}
```

### Exemplo com Fila
```c
#include "Fila.h"

int main() {
    // Criando e populando a fila
    Fila *f = fila_criar();
    
    // Inserindo elementos (sempre no fim)
    fila_inserir(f, 10);  // Fila: [10]
    fila_inserir(f, 20);  // Fila: [10, 20]
    fila_inserir(f, 30);  // Fila: [10, 20, 30]
    
    // Imprimindo a fila
    fila_imprimir(f);  // Fila: [10, 20, 30]
                       // Frente -> [primeiro elemento] ... [último elemento] <- Fundo
    
    // Removendo elementos (sempre do início)
    fila_remover(f);   // Remove: 10
    fila_imprimir(f);  // Fila: [20, 30]
    
    // Verificando se está vazia
    if(!fila_vazia(f)) {
        printf("Fila ainda contém elementos!\n");
    }
    
    // Liberando a memória
    fila_destruir(f);
    return 0;
}
```

### Exemplo com Pilha
```c
#include "Pilha.h"

int main() {
    // Criando e populando a pilha
    Pilha *p = pilha_criar();
    
    // Empilhando elementos (push)
    pilha_push(p, 10);  // Base -> 10
    pilha_push(p, 20);  // Base -> 10, 20
    pilha_push(p, 30);  // Base -> 10, 20, 30 <- Topo
    
    // Imprimindo a pilha
    pilha_imprimir(p);  /* Saída:
                           Pilha: (topo)
                              |  30  |
                              |  20  |
                              |  10  |
                              +-----+
                              (base)  */
    
    // Desempilhando elementos (pop)
    pilha_pop(p);      // Remove: 30 (topo)
    pilha_imprimir(p); // Mostra: 20, 10
    
    // Verificando se está vazia
    if(!pilha_vazia(p)) {
        printf("Pilha ainda contém elementos!\n");
    }
    
    // Liberando a memória
    pilha_destruir(p);
    return 0;
}
```

[Exemplos similares para Fila e Pilha...]

## ⚙️ Complexidade das Operações

### Lista Encadeada
| Operação | Complexidade | Descrição |
|----------|-------------|------------|
| Inserir início | O(1) | Constante |
| Inserir fim | O(1) | Constante |
| Remover início | O(1) | Constante |
| Remover fim | O(n) | Linear |
| Buscar elemento | O(n) | Linear |
| Verificar vazia | O(1) | Constante |

### Fila (FIFO)
| Operação | Complexidade | Descrição |
|----------|-------------|------------|
| Inserir (enqueue) | O(1) | Constante - Insere no fim da fila |
| Remover (dequeue) | O(1) | Constante - Remove do início da fila |
| Verificar vazia | O(1) | Constante - Verifica se há elementos |
| Acessar frente | O(1) | Constante - Consulta primeiro elemento |
| Destruir fila | O(n) | Linear - Libera todos os elementos |
| Imprimir | O(n) | Linear - Percorre todos os elementos |

### Pilha (LIFO)
| Operação | Complexidade | Descrição |
|----------|-------------|------------|
| Push | O(1) | Constante - Insere no topo da pilha |
| Pop | O(1) | Constante - Remove do topo da pilha |
| Verificar vazia | O(1) | Constante - Verifica se há elementos |
| Acessar topo | O(1) | Constante - Consulta elemento do topo |
| Destruir pilha | O(n) | Linear - Libera todos os elementos |
| Imprimir | O(n) | Linear - Percorre todos os elementos |

### Notas sobre Complexidade
- **Lista Encadeada**: Mantém operações O(1) para inserção e remoção no início devido ao acesso direto ao primeiro nó. A remoção no fim é O(n) pois requer percorrer a lista até o penúltimo elemento.
  
- **Fila**: Alcança O(1) em suas operações principais (inserir/remover) por utilizar a lista encadeada de maneira otimizada:
  - Inserção: usa o fim da lista (O(1))
  - Remoção: usa o início da lista (O(1))

- **Pilha**: Também atinge O(1) em suas operações principais realizando todas as operações no início da lista:
  - Push: insere no início (O(1))
  - Pop: remove do início (O(1))

### Uso de Memória
- Cada nó da estrutura ocupa:
  - 4 bytes para o valor (int)
  - 8 bytes para o ponteiro próximo
  - Total: 12 bytes por elemento
- Estrutura de controle:
  - Lista: 16 bytes (dois ponteiros)
  - Fila: 16 bytes (encapsula uma Lista)
  - Pilha: 16 bytes (encapsula uma Lista)

## 📝 Licença
Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 📧 Contato
Daniel Trindade - [@Dan13lTr1ndad3](https://x.com/Dan13lTr1ndad3) - 
danieloliveiratrindade@gmail.com

Link do Projeto: [https://github.com/DanielTrindade/Tipos-abstratos-de-dados-basicos](https://github.com/DanielTrindade/Tipos-abstratos-de-dados-basicos)

## 📚 Referências
- Introduction to Algorithms, CLRS
- Data Structures and Algorithm Analysis in C
- [GeeksforGeeks - Data Structures](https://www.geeksforgeeks.org/data-structures/)

## 📈 Roadmap
- [ ] Adicionar busca por valor
- [ ] Suporte a tipos genéricos (void*)
