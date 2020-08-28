#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int code;
  double speed;
  double price;
  struct list *next;
}list;

list *linked_node(list *p, int a){  
  list *copy = malloc(sizeof(list));
  list *walker = malloc(sizeof(list));
  
  copy->code= a;
  copy->next = NULL;

  if(p==NULL)
    return copy;

  else{
    walker = p;

    while(walker->next != NULL)
      walker = walker->next;

    walker->next = copy;
    return p;
  }
}

void selection_sort(list *p){
  
  if(p->next == NULL){
    return;
  }

  int menor= p->code;
  int cont1 = 0;
  int index, i, aux;

  list *walker = p;
  list *walker2 = p;

  while(walker != NULL){
    if(menor >= walker->code){
      menor = walker->code;
      index = cont1;
    }        
    cont1++;
    walker= walker->next;
  }

  for(i=0; i<index; i++){
    walker2= walker2->next;
  }
  
  aux = walker2->code;
  walker2->code = p->code;
  p->code = aux;

  selection_sort(p->next);
} 

void print_list(list *p){

  while(p!=NULL){
    printf("%d ", p->code);
    p=p->next;
  }

}

int main(void) {
  list *linkedList = NULL;

  linkedList = linked_node(linkedList, 10);
  linkedList = linked_node(linkedList, 5);  
  linkedList = linked_node(linkedList, 3);
  linkedList = linked_node(linkedList, 12);
  linkedList = linked_node(linkedList, 7);

  print_list(linkedList);      
  printf("\n\n");

  selection_sort(linkedList);
  print_list(linkedList);
  printf("\n\n");

}