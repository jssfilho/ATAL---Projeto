#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct ponto Ponto;
struct ponto{
    double x;
    double y;
  };
double closeatPair(Ponto * p, long i, long f);
void mergeSort(Ponto * a,long i, long f);
double distance(Ponto p, Ponto q);
void mergeSortY(Ponto * a,long i, long f);

int main(int argc, char** argv) {
  long num_pontos;
  scanf("%ld",&num_pontos);
  while (num_pontos!=0){
    Ponto * lista  =  (Ponto *) malloc(num_pontos*sizeof(Ponto));
    long i;
    for (i = 0; i < num_pontos; i++) {
        scanf("%lf %lf",&lista[i].x, &lista[i].y);
    }
    mergeSort(lista,0,num_pontos-1);
    double resu = closeatPair(lista, 0,num_pontos-1);
    if(resu<=10000){
      printf("%.4lf\n",resu);
    }else{
      printf("INFINITY\n");
    }


    scanf("%ld",&num_pontos);

  }

  return 0;
}


double distance(Ponto p, Ponto q){
  double dis = sqrt((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
  return dis;
}
double minimo(double a, double b){
  return (a<=b)?a:b;
}
double forcaBruta(Ponto * p, long c, long f){
    double dmin = 999999.1;
    long n = f-c;
    long i,j;
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            if (distance(p[i], p[j]) < dmin)
                dmin = distance(p[i], p[j]);
  return dmin;
}
double closeatPair(Ponto * p, long i, long f){
  if((f-i)<=2){
    return forcaBruta(p,i,f);
  }
  long m = (i+f)/2;
  double d1 =closeatPair(p,i,m);
  double d2 =closeatPair(p,m+1,f);
  double dmin =minimo(d1,d2);
  Ponto * aux = (Ponto *) malloc((f-i+1)*sizeof(Ponto));
  long k,j;
  long tamAux = 0;
  long iAux=0;
  double v;
  for(k=i;k<f;k++){
    if(abs(p[k].x-p[m].x)<dmin){
      aux[iAux]=p[k];
      iAux+=1;
      tamAux+=1;
    }
  }
  mergeSortY(aux,0,tamAux-1);
  for(k=0;k<tamAux;k++){
    for(j=k+1;j<tamAux;j++){
      double n = aux[k].y-aux[m].y;
      if(abs(n)>dmin)
        break;
      v = distance(aux[k],aux[j]);
      if(v<dmin)
        dmin=v;
    }
  }
  return dmin;
}

void merge(Ponto * a,long c,long m, long f){
  long tamE=m-c+1;
  long tamD = f-m;
  Ponto * direita = (Ponto *) malloc((tamD)*sizeof(Ponto));
  Ponto * esquerda = (Ponto *) malloc((tamE)*sizeof(Ponto));
  long i,j,k;

  for (i = 0; i < tamE; i++)
        esquerda[i] = a[c + i];
  for (j = 0; j < tamD; j++)
        direita[j] = a[m +1+ j];

  i = 0;
  j = 0;
  k = c;

  while (i < tamE && j < tamD)
  {
      if (esquerda[i].x <= direita[j].x) {
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
void mergeSort(Ponto * a,long i, long f){
    if(f>i){
      long m = (i+f)/2;
      mergeSort(a,i,m);
      mergeSort(a,m+1,f);
      merge(a,i,m,f);
    }
}
void mergeY(Ponto * a,long c,long m, long f){
  long tamE=m-c+1;
  long tamD = f-m;
  Ponto * direita = (Ponto *) malloc((tamD)*sizeof(Ponto));
  Ponto * esquerda = (Ponto *) malloc((tamE)*sizeof(Ponto));
  long i,j,k;

  for (i = 0; i < tamE; i++)
        esquerda[i] = a[c + i];
  for (j = 0; j < tamD; j++)
        direita[j] = a[m +1+ j];

  i = 0;
  j = 0;
  k = c;

  while (i < tamE && j < tamD)
  {
      if (esquerda[i].y <= direita[j].y) {
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
void mergeSortY(Ponto * a,long i, long f){
    if(f>i){
      long m = (i+f)/2;
      mergeSortY(a,i,m);
      mergeSortY(a,m+1,f);
      mergeY(a,i,m,f);
    }
}
