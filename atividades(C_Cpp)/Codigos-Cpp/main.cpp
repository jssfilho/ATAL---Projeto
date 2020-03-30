#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
long max(long a, long b, long c);
long subArrayMax(long* a, int i, int f);
long maxMeio(long* a, int i, int f);

int main(int argc, char** argv) {
  long ganho;
  int num_apostas;
  cin >> num_apostas;
  while (num_apostas!=0){
    //lista  =  (long*) malloc(num_apostas*sizeof(long long));
    long lista [num_apostas];
    for(int i=0;i<num_apostas;i++){
      cin >> lista[i];
    }
    //for(int i =0; i<=num_apostas; i++ ){cout <<"\n"<< lista[i];}
    ganho = subArrayMax(lista, 0, num_apostas-1);
    if (ganho<=0)
      cout << "Losing streak\n";
    else
      cout << "The maximum winning streak is " << ganho <<"\n";
    cin >> num_apostas;
  }


	return 0;
}

long max(long a,long b,long c){
	return a>b?(a>c? a:c):(b>c?b:c);
}
long maxMeio(long* a, int i, int f){
	long  se =0 ,sd =0;
	long  ms1 =-9999999l,ms2 =-9999999l;
	int m = (i+f)/2;
  for(int k = m;k>=i;k--){
		se += a[k];
		if(se>ms1){
			ms1=se;
		}
	}
	for(int k = m+1;k<=f;k++){
		sd+=a[k];
		if(sd>ms2){
			ms2=sd;
		}
	}
  //cout << ms1+ms2  << '\n';
	return ms1+ms2;

}

long subArrayMax(long* a, int i, int f){
	if(i==f){
		return a[i];
	}
	int m= (i+f)/2;
	long s1 = subArrayMax(a, i, m);
	long s2 = subArrayMax(a, m+1, f);
	long sm = maxMeio(a,i,f);

	return max(s1,s2,sm);
}
