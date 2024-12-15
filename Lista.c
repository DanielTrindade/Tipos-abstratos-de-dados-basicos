#include "Lista.h"


No *criar_no(int num) {
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = num;
  novo_no->prox = NULL;
  return novo_no;
}


Lista *lst_criar() {
  Lista *lst = malloc(sizeof(Lista));
  lst->prim = lst->ult = NULL;
  return lst;
}

void lst_inserir_inicio(Lista *lst, int num) {
  //criar o nó
  No *no = criar_no(num);
  if(lst->prim == NULL) {
    lst->ult = lst->prim = no;
  } else {
    //o antigo primeiro é o proximo do novo no
    no->prox = lst->prim;
    //o novo no agora é o novo primeiro
    lst->prim = no;
  }
}

void lst_inserir_fim(Lista *lst, int num) {
  //criar o nó
  No *no = criar_no(num);
  if(lst->ult == NULL) {
    lst->ult = lst->prim = no;
  } else {
    //o novo nó é o proximo do ultimo
    lst->ult->prox = no;
    //o novo nó é o ultimo agora
    lst->ult = no;
  }
}


void lst_remover_inicio(Lista *lst) {
  if(lst != NULL && lst->prim != NULL) {
    No *aux = lst->prim;
    lst->prim = lst->prim->prox;
    if(lst->prim == NULL) {
      lst->ult = NULL;
    }
    free(aux);
  }
}


void lst_remover_final(Lista *lst) {
  //lista vazia
  if(lst == NULL || lst->prim == NULL)
    return;
  //caso tem apenas 1 elemento
  if(lst->prim == lst->ult) {
    free(lst->prim);
    lst->prim = lst->ult = NULL;
    return;
  }
  //tem mais de 1 elemento
  No *atual = lst->prim;
  No *ant = NULL;
  while(atual != lst->ult) {
    ant = atual;
    atual = atual->prox;
  }
  ant->prox = NULL;
  lst->ult = ant;
  free(atual);
}


void lst_limpar(Lista *lst) {
  if(lst == NULL || lst->prim == NULL)
    return;
  No *atual = lst->prim;
  while(atual != NULL) {
    No *aux = atual;
    atual = atual->prox;
    free(aux);
  }
  lst->ult = NULL;
  free(lst);
}


void lst_imprimir(Lista *lst) {
  for(No *atual = lst->prim; atual != NULL; atual = atual->prox) {
    printf("%d ", atual->valor);
  }
  printf("\n");
}