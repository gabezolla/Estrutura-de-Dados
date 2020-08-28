#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
  int key;
} registro;

void swap(registro *a, registro *b){
  int aux = a->key;
  a->key = b->key;
  b->key = aux;
}

void max_heapify(registro *base, int node, int n) {
  int left = 2*node + 1, right = 2*node + 2;
  int largest = node;

  if(left < n && base[left].key > base[largest].key)
    largest = left;

  if(right < n && base[right].key > base[largest].key)
    largest = right;

  if(largest != node){
    swap(base+node, base+largest);
    max_heapify(base, largest, n);
  }
}

void heapSort(registro *base, int n) {

  for (int i=n/2-1; i>=0; i--)
    max_heapify(base, i, n);

  for (int i=n-1; i>0; i--){
    swap(base, base+i);
    --n;
    max_heapify(base, 0, n);
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
  v[6].key = 3;

  heapSort(v, 7);

  for(i=0; i<7; i++){
    printf("%d ", v[i].key);
  }
}