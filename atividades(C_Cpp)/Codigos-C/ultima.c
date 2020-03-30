#include <stdio.h>
#include <stdlib.h>

void mergeSort(long * a,int i, int f);

int main(int argc, char** argv) {
  int num_pontos;
  scanf("%i",&num_pontos);
  while (num_pontos!=0){

    long * lista = (long *) malloc(num_pontos*sizeof(long));
    int i;
    for(i=0;i<num_pontos;i++){
      scanf("%ld",&lista[i]);
    }
    mergeSort(lista,0,num_pontos-1);
    for(i=0;i<num_pontos;i++){
      if(i==num_pontos-1)
        printf("%ld", lista[i]);
      else
        printf("%ld ", lista[i]);
    }
    printf("\n");
    scanf("%i",&num_pontos);
  }
  return 0;
}

void merge(long * a,int c,int m, int f){
  int tamE=m-c+1;
  int tamD = f-m;
  long * direita = (long *) malloc((tamD)*sizeof(long));
  long * esquerda = (long *) malloc((tamE)*sizeof(long));
  int i,j,k;

  for (i = 0; i < tamE; i++)
        esquerda[i] = a[c + i];
  for (j = 0; j < tamD; j++)
        direita[j] = a[m +1+ j];

  i = 0;
  j = 0;
  k = c;

  while (i < tamE && j < tamD)
  {
      if (esquerda[i] <= direita[j]) {
          a[k] = esquerda[i];
          i++;
      }
      else{
          a[k] = direita[j];
          j++;
      }
      k++;
  }
  while (i < tamE) {
        a[k] = esquerda[i];
        i++;
        k++;
  }
  while (j < tamD){
        a[k] = direita[j];
        j++;
        k++;
  }

}
void mergeSort(long * a,int i, int f){
    if(f>i){
      int m = (i+f)/2;
      mergeSort(a,i,m);
      mergeSort(a,m+1,f);
      merge(a,i,m,f);
    }
}
