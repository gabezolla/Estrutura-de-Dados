#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int aux;
  aux = *b;
  *b = *a;
  *a = aux;
}

int partition(int *base, int n){
  int pivot = base[0];
  int i = 1; int j;
  
  for(j=1; j<n; j++){
    
    if(base[j] < pivot){
      swap(base+i, base+j);
      ++i;
    }   
  }

  swap(base+i-1, base);
  return i-1;
}

void quick_sort(int *base, int n){

  if(n>0){    
    int p = partition(base, n);
    quick_sort(base, p);
    quick_sort(base+p+1, n-p-1);    
  }
}

int main(void) {
  int i;
  int *v; 
  int vetor[6] = {1, 5, 3, 8, 9, 6}; 
  v = vetor;

  quick_sort(v, 6);

  for(i=0; i<6; i++){
    printf("%d ", v[i]);
  }  
  
}