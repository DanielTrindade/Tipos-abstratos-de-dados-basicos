#ifndef FILA_H
#define FILA_H

#include "Lista.h"

/**
 * @brief Estrutura que encapsula uma lista para implementar uma fila
 * 
 * @details Utiliza a implementação de lista encadeada internamente
 * para fornecer as operações de fila (FIFO - First In First Out)
 */
typedef struct fila {
    Lista *lst;     //Lista encadeada usada internamente
} Fila;

/**
 * @brief Cria uma nova fila vazia
 * 
 * @return Fila* Ponteiro para a nova fila criada
 */
Fila *fila_criar(void);

/**
 * @brief Verifica se a fila está vazia
 * 
 * @param f Ponteiro para a fila
 * @return int 1 se vazia, 0 caso contrário
 */
int fila_vazia(Fila *f);

/**
 * @brief Insere um elemento no final da fila
 * 
 * @param f Ponteiro para a fila
 * @param num Valor a ser inserido
 */
void fila_inserir(Fila *f, int num);

/**
 * @brief Remove o primeiro elemento da fila
 * 
 * @param f Ponteiro para a fila
 */
void fila_remover(Fila *f);

/**
 * @brief Imprime todos os elementos da fila
 * 
 * @param f Ponteiro para a fila
 */
void fila_imprimir(Fila *f);

/**
 * @brief Libera toda a memória alocada para a fila
 * 
 * @param f Ponteiro para a fila
 */
void fila_destruir(Fila *f);

#endif