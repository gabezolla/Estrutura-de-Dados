#include <stdio.h>
#include <stdlib.h>

struct lista{
  int valor;
  struct lista *prox;
};

struct lista *add_valor(struct lista *node, int elemento){
  struct lista *p = malloc(sizeof(struct lista));
  struct lista *novo = malloc(sizeof(struct lista));

  novo->valor = elemento;
  novo->prox = NULL;
  
  if(node==NULL){
    return novo;    
  }

  else{
    p = node;
    while(p->prox != NULL){
      p = p->prox;
    }

    p->prox = novo;
    return node;
  }
}

struct lista *inserir_elemento(struct lista *node, struct lista *copia, int posicao, int elemento){

  struct lista *q = malloc(sizeof(struct lista));
  struct lista *r = malloc(sizeof(struct lista));
  struct lista *s = malloc(sizeof(struct lista));
  int i;

  q = node;
  s = copia;
  r->valor = elemento;

  for(i=0; i<posicao-1; i++){
    q = q->prox;
    s = s->prox;
  }

  q->valor = r->valor;
  q->prox = s->prox;
  return node;
}

struct lista *inserir_fim(struct lista *node, struct lista *copia, int elemento){
  struct lista *f = malloc(sizeof(struct lista));
  struct lista *num = malloc(sizeof(struct lista));

  f = node;
  num->valor = elemento;

  while(f->prox!=NULL){
    f= f->prox;
  }

  f->prox = num;
  f->prox->prox = NULL;
  
  return node;
}

struct lista *remover_elemento(struct lista *node, int posicao){
  struct lista *remove = malloc(sizeof(struct lista));
 
  int i;
  remove=node;

  for(i=0; i<posicao-1; i++){
    remove= remove->prox;
  }

  remove->valor = remove->prox->valor;
  remove->prox = remove->prox->prox; 
  return node;
}

void print_lista(struct lista *node){
  while(node!=NULL){
    printf("%d ", node->valor);
    node = node->prox;
  }
}

void free_list(struct lista *node){
  struct lista *liberar;
  
  while(node!= NULL){
    liberar = node;
    node = node->prox;
    free(liberar);
  }
}

int main(void) {
  
  struct lista *node = NULL;
  struct lista *copia = NULL;
  struct lista *copia2 = NULL; 
  int n, elemento, posicao, elementofim, remover;
  printf("Lista inicial: ");

  scanf("%d", &n);

  while(n>=0){ // ao digitar números negativos, paramos de adicionar à lista.
    node = add_valor(node, n);
    copia = add_valor(copia, n);
    copia2 = add_valor(copia2, n);
    scanf("%d", &n);
  }

  print_lista(node);
    
  printf("\nAdicionar elemento: "); // adicionar ou substituir
  scanf("%d", &elemento);
  printf("Posicao: ");
  scanf("%d", &posicao);

  node = inserir_elemento(node, copia, posicao, elemento);
  print_lista(node);

  printf("\nAdicionar no fim o elemento: ");
  scanf("%d", &elementofim);
  node = inserir_fim(node, copia2, elementofim);
  print_lista(node);

  printf("\nRemover qual posicao: ");
  scanf("%d", &remover);
  node = remover_elemento(node, remover);
  print_lista(node);  
}