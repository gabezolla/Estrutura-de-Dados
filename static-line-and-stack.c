#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TYPE int

typedef struct fila{
  int front;
  int back;  
  TYPE dado[SIZE];
  
}fila;

typedef struct pilha{
  int top;
  TYPE dado[SIZE];
   
}pilha;

fila create_fila(){
  fila f;
  f.front = -1;
  f.back = -1;
  return f;
}

pilha create_pilha(){
  pilha p;
  p.top = -1;
  return p;
}

pilha *push_pilha(pilha *p, TYPE num){
  if(p->top+1<SIZE){
    ++p->top; // pré-incremento para n ficar nada na posição -1
    p->dado[p->top] = num; // valor na posição p->top recebe num;
    return p;
  }

  else
    return NULL;
}

TYPE *pop_pilha(pilha *p){ // pop para pilha
  if(p->top == -1)
    return NULL;

  --p->top;
  return &(p->dado[p->top+1]); // return int apenas para printar a pilha
}

fila *push_fila(fila *f, TYPE num){
  if(f->back+1 > SIZE) 
    return NULL;
  
  if(f->front == -1)
    f->front = 0;
  
  f->back= f->back+1;
  f->dado[f->back]= num;
  return f;

}

TYPE *pop_fila(fila *f){

  TYPE mark; // variável para marcar f e incrementar antes do return
  mark = f->front;

  if(f->front==-1)
    return NULL;

  if(f->front == f->back)
    f->front = f->back = -1;
  
  else
    f->front++; // anda front até chegar em front = back
    
  return &(f->dado[mark]);  
}

int main(void) {
  pilha p = create_pilha();
  fila f = create_fila();
  int i;
  TYPE *x; // endereço para anexar os valores empilhados (pilha)
  TYPE *y; // endereço para anexar valores enfileirados (fila)

  for(i=0; i<SIZE; i++){
    if(push_pilha(&p, i)==NULL)
      printf("Estouro de pilha\n");      
  }

  printf("Pilha: \n");
  while((x=pop_pilha(&p)) != NULL){
    printf("%d ", *x);
  }

  printf("\nFila: \n");

  for(i=0; i<SIZE; i++){
    if(push_fila(&f, i) == NULL)
      printf("Estouro de fila\n");
    }

  while((y=pop_fila(&f))!=NULL){
    printf("%d ", *y);
  }

  printf("\n");
  
}