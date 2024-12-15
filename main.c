#include "Fila.h"
#include "Pilha.h"

int main(void) {
  int n;
  Fila *f = fila_criar();
  Pilha *p = pilha_criar();
  while(scanf("%d", &n), n != 0) {
    fila_inserir(f, n);
  }
  fila_imprimir(f);
  while(scanf("%d", &n), n != 0) {
    pilha_push(p, n);
  }
  pilha_imprimir(p);
  fila_destruir(f);
  pilha_destruir(p);
  return 0;
}