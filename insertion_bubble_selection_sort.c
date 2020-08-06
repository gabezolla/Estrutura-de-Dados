#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
  int key;
}registro;

// ~~~~~~~~~~~~~~~~~~~~~ INSERTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void insert(registro *base, int k) {
  registro x = base[k];
  --k;

  while (k >= 0 && base[k].key > x.key){
    base[k+1] = base[k];
    --k;
  }

  base[k+1] = x;
}

void insertionSort(registro *base, int n) {
  int k = 1;

  while (k < n){
    insert(base, k);
    ++k;
  }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~ BUBBLE SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

void swap(registro *a, registro *b){
  int aux = a->key;
  a->key = b->key;
  b->key = aux;
}

char bubbleUp(registro *base, int n) {
  char changed = 0;
  for (int i=0; i<n-1; i++){

    if (base[i].key > base[i+1].key){
      swap(base+i, base+i+1);
      changed = 1;
    }
  }

return changed; // se retornar 0, vai parar o while do bubble sort, quer dizer que já está tudo ordenado
}

void bubbleSort(registro *base, int n) {
  while (bubbleUp(base, n));
}

// ~~~~~~~~~~~~~~~~~~~~~~~ SELECTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int find_min(registro *base, int n){
  int minimo, i;
  int j; // guarda o indice minimo
  minimo = base[n].key;

  for(i=0; i<n; i++){    
    if(base[i].key < minimo){
      minimo = base[i].key;
      j = i;
    }
  }

  return j;  
}

void selectionSort(registro *base, int n) {
  int i, j, i_min;
  for (j=0; j<n-1; j++){
    i_min = find_min(base + j, n-j) + j;

    if (i_min != j) 
      swap(base+i_min, base+j);
  }
}

int main(void) {
  registro *v; 
  int i; 

  v[0].key = 4;
  v[1].key = 3;
  v[2].key = 6;
  v[3].key = 2;
  v[4].key = 1;
  v[5].key = 8;
  v[6].key = 0;

  selectionSort(v, 7); // calling function

  for(i=0; i<7; i++){
    printf("%d ", v[i].key);
  }
}