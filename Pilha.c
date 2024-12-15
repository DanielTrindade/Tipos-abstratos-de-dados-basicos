#include "Pilha.h"

/**
 * @brief Cria uma nova pilha vazia
 */
Pilha *pilha_criar() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->lst = lst_criar();
    }
    return p;
}

/**
 * @brief Verifica se a pilha está vazia
 */
int pilha_vazia(Pilha *p) {
    if (p == NULL || p->lst == NULL) return 1;
    return p->lst->prim == NULL;
}

/**
 * @brief Insere um elemento no topo da pilha
 */
void pilha_push(Pilha *p, int num) {
    if (p != NULL && p->lst != NULL) {
        lst_inserir_inicio(p->lst, num);
    }
}

/**
 * @brief Remove o elemento do topo da pilha
 */
void pilha_pop(Pilha *p) {
    if (p != NULL && p->lst != NULL) {
        lst_remover_inicio(p->lst);
    }
}

/**
 * @brief Imprime os elementos da pilha na ordem LIFO (último a entrar, primeiro a sair)
 * 
 * @details Imprime de cima para baixo, onde o elemento do topo
 * (último inserido) aparece primeiro
 */
void pilha_imprimir(Pilha *p) {
    if (p != NULL && p->lst != NULL) {
        printf("Pilha: (topo)\n");
        No *atual = p->lst->prim;
        
        while (atual != NULL) {
            printf("   |  %02d  |\n", atual->valor);
            atual = atual->prox;
        }
        printf("   +-----+\n");
        printf("   (base)\n");
    }
}

/**
 * @brief Libera toda a memória alocada para a pilha
 */
void pilha_destruir(Pilha *p) {
    if (p != NULL) {
        lst_limpar(p->lst);
        free(p);
    }
}