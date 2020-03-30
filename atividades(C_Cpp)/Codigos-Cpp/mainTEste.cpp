#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXDIG 4

using namespace std;
int inverte(int num){
	if (num<10)
		return num;
	int numeros[MAXDIG]={0};
	int cont=0;
	for(int i=0;i<MAXDIG;i++){
   		numeros[i] = num%10;
   		num /= 10;
   		
		if(num==0)
			break;
		cont++;	
   	}
   	int resu=0;
	for(int i=0;i<MAXDIG;i++){
		resu+=numeros[i]*pow(10,cont);
		cont--;
		if(cont<0)
			break;
	}
	return resu;
}

int main(int argc, char** argv) {
	int num;
	cin>>num;
	cout<<inverte(num);
	return 0;
}
