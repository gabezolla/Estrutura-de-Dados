#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
  int top;
  char data[100];  
}pilha;

pilha create_pilha(){
  pilha p;
  p.top=-1;
  return p;
}

pilha *push(pilha *p, char c){
  if(p->top > 100)
    return NULL;

  p->data[++p->top]= c;
  return p;    
}

char *pop(pilha *p){
  int mark = p->top;

  if(p->top == -1)
    return NULL;

  p->top--;

  return &(p->data[mark]);
}

int main(void) {
  pilha p = create_pilha();
  char c[100];
  fgets(c, 100, stdin);
  int len = strlen(c)-1;
  int i;
  char *x;

  for(i=0; i<len; i++){
    if(push(&p, c[i])==NULL)
      printf("Estouro.");
  }
  
  int contA=0, contB=0, contC=0;
  char compare;

  while((pop(&p))!=NULL){
    compare = *pop(&p);

    if(compare == '(')
      contA++;

    if(compare == ')')
      contA--;

    if(compare == '{')
      contB++;

    if(compare == '}')
      contB--;

    if(compare == '[')    
      contC++;    
    
    if(compare == ']')
      contC--;
  }
  
  if(contA != 0 || contB != 0 || contC != 0)
    printf("Não foram fechadas");

  else
    printf("Foram fechadas");

}