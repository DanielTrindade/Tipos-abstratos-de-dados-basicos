#ifndef PILHA_H
#define PILHA_H

#include "Lista.h"

/**
 * @brief Estrutura que encapsula uma lista para implementar uma pilha
 * 
 * @details Utiliza a implementação de lista encadeada internamente
 * para fornecer as operações de pilha (LIFO - Last In First Out)
 */
typedef struct pilha {
    Lista *lst;     ///< Lista encadeada usada internamente
} Pilha;

/**
 * @brief Cria uma nova pilha vazia
 * 
 * @return Pilha* Ponteiro para a nova pilha criada
 */
Pilha *pilha_criar(void);

/**
 * @brief Verifica se a pilha está vazia
 * 
 * @param p Ponteiro para a pilha
 * @return int 1 se vazia, 0 caso contrário
 */
int pilha_vazia(Pilha *p);

/**
 * @brief Insere um elemento no topo da pilha
 * 
 * @param p Ponteiro para a pilha
 * @param num Valor a ser inserido
 */
void pilha_push(Pilha *p, int num);

/**
 * @brief Remove o elemento do topo da pilha
 * 
 * @param p Ponteiro para a pilha
 */
void pilha_pop(Pilha *p);

/**
 * @brief Imprime todos os elementos da pilha
 * 
 * @param p Ponteiro para a pilha
 */
void pilha_imprimir(Pilha *p);

/**
 * @brief Libera toda a memória alocada para a pilha
 * 
 * @param p Ponteiro para a pilha
 */
void pilha_destruir(Pilha *p);

#endif