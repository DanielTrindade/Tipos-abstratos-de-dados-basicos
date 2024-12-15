#include "Fila.h"

/**
 * @brief Cria uma nova fila vazia
 */
Fila *fila_criar() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->lst = lst_criar();
    }
    return f;
}

/**
 * @brief Verifica se a fila está vazia
 */
int fila_vazia(Fila *f) {
    if (f == NULL || f->lst == NULL) return 1;
    return f->lst->prim == NULL;
}

/**
 * @brief Insere um elemento no final da fila
 */
void fila_inserir(Fila *f, int num) {
    if (f != NULL && f->lst != NULL) {
        lst_inserir_fim(f->lst, num);
    }
}

/**
 * @brief Remove o primeiro elemento da fila
 */
void fila_remover(Fila *f) {
    if (f != NULL && f->lst != NULL) {
        lst_remover_inicio(f->lst);
    }
}

/**
 * @brief Imprime todos os elementos da fila
 */
/**
 * @brief Imprime os elementos da fila na ordem FIFO (primeiro a entrar, primeiro a sair)
 * 
 * @details Imprime da esquerda para direita, onde o elemento mais à esquerda
 * é o primeiro a ser removido e o mais à direita é o último inserido
 */
void fila_imprimir(Fila *f) {
    if (f != NULL && f->lst != NULL) {
      printf("Fila: [");
      No *atual = f->lst->prim;
      
      // Imprime o primeiro sem vírgula
      if (atual != NULL) {
          printf("%d", atual->valor);
          atual = atual->prox;
      }
      
      // Imprime os demais elementos com vírgula
      while (atual != NULL) {
          printf(", %d", atual->valor);
          atual = atual->prox;
      }
      printf("]\n");
      printf("Frente -> [primeiro elemento] ... [último elemento] <- Fundo\n");
    }
}

/**
 * @brief Libera toda a memória alocada para a fila
 */
void fila_destruir(Fila *f) {
    if (f != NULL) {
        lst_limpar(f->lst);
        free(f);
    }
}