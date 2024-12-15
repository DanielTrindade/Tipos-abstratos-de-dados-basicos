#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
typedef struct lista Lista;

/**
 * @brief Estrutura que representa um nó individual na lista encadeada.
 * 
 * @details Cada nó contém um valor inteiro e um ponteiro para o próximo elemento,
 * permitindo assim a construção de uma sequência encadeada de elementos.
 */
typedef struct no {
    int valor;      // Valor inteiro armazenado no nó
    struct no *prox; // Ponteiro para o próximo nó da lista
} No;

/**
 * @brief Estrutura de controle para gerenciar a lista encadeada.
 * 
 * @details Mantém ponteiros para o primeiro e último elementos da lista,
 * facilitando operações de inserção e remoção em ambas as extremidades.
 */
typedef struct lista {
    No *prim;       // Ponteiro para o primeiro nó da lista
    No *ult;        // Ponteiro para o último nó da lista
} Lista;

/**
 * @brief Cria um novo nó com o valor especificado
 * 
 * @param num Valor inteiro a ser armazenado no nó
 * @return No* Ponteiro para o novo nó criado
 */
No *criar_no(int num);

/**
 * @brief Cria uma nova lista vazia
 * 
 * @return Lista* Ponteiro para a nova lista criada
 */
Lista *lst_criar(void);

/**
 * @brief Insere um elemento no início da lista
 * 
 * @param lst Ponteiro para a lista
 * @param num Valor a ser inserido
 */
void lst_inserir_inicio(Lista *lst, int num);

/**
 * @brief Insere um elemento no final da lista
 * 
 * @param lst Ponteiro para a lista
 * @param num Valor a ser inserido
 */
void lst_inserir_fim(Lista *lst, int num);

/**
 * @brief Remove o primeiro elemento da lista
 * 
 * @param lst Ponteiro para a lista
 */
void lst_remover_inicio(Lista *lst);

/**
 * @brief Remove o último elemento da lista
 * 
 * @param lst Ponteiro para a lista
 */
void lst_remover_final(Lista *lst);

/**
 * @brief Libera toda a memória alocada para a lista
 * 
 * @param lst Ponteiro para a lista
 */
void lst_limpar(Lista *lst);

/**
 * @brief Imprime todos os elementos da lista
 * 
 * @param lst Ponteiro para a lista
 */
void lst_imprimir(Lista *lst);


#endif