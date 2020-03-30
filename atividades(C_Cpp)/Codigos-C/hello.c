#include <stdio.h>
#include <stdlib.h>


long max(long a, long b,long c);
long subArrayMax(long* a, long i, long f);
long maxMeio(long* a, long i, long f);

int main(int argc, char** argv) {
  long num_apostas;
  scanf("%ld",&num_apostas);
  while (num_apostas!=0){
    long * lista  =  (long *) malloc(num_apostas*sizeof(long));
    int i;
    for(i=0;i<num_apostas;i++){
      scanf("%ld",&lista[i]);
    }

    long ganho = subArrayMax(lista, 0, num_apostas-1);
    if (ganho<=0){
      printf("Losing streak.\n");
    }else{
      printf("The maximum winning streak is %ld.\n", ganho);
    }
    scanf("%ld",&num_apostas);
  }


	return 0;
}


long max(long a,long b,long c){
	return a>b?(a>c? a:c):(b>c?b:c);
}
long maxMeio(long* a, long i, long f){
	long  se =0 ,sd =0;
	long  ms1 =-1,ms2 =-1;
	long m = (i+f)/2;
  long k;
  for(k = m;k>=i;k--){
		se += (a[k]);
		if(se>ms1){
			ms1=se;
		}
	}
	for(k = m+1;k<=f;k++){
		sd+=a[k];
		if(sd>ms2){
			ms2=sd;
		}
	}
	return ms1+ms2;
}

long subArrayMax(long* a, long i, long f){
	if(i==f){
		return a[i];
	}
	long m= (i+f)/2;
	long s1 = subArrayMax(a, i, m);
	long s2 = subArrayMax(a, m+1, f);
	long sm = maxMeio(a,i,f);

	return max(s1,s2,sm);
}
