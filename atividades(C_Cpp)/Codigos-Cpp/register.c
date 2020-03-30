#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main(int argc, char** argv) {
  int num_apostas = 0;
  int quant;
  char * instru;
  int * listaTime  =  (int *) malloc(MAX*sizeof(int));
  int * listaInst  =  (int *) malloc(MAX*sizeof(int));
  while (1){
    scanf("%s %i %i",instru, &listaInst[num_apostas], &listaTime[num_apostas]);
    if(instru[0]=='#'){
      scanf("%i",&quant);
      printf("teste");
      break;
    }else{
      num_apostas+=1;
    }
  }
  int i=0;
  int * listaCom  =  (int *) malloc(num_apostas*sizeof(int));
  for(i=0;i<num_apostas;i++){
    listaInst[i]=0;
  }
  int j=0;
  while (j<quant){
    for(i=0;i<num_apostas;i++){
      listaInst[i]+=1;
      if(listaCom[i]==listaTime[i]){
        listaCom[i]=0;
        printf("%i\n",listaInst[i]);
        j++;
      }
    }
  }


	return 0;
}
