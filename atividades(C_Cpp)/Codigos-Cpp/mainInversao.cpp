#include <iostream>
#include <math.h>
#include <deque>
#define MAXDIG 6

using namespace std;
int testeBFS(int a, int b);
int main(int argc, char** argv) {
	int numTestes;
	cin>>numTestes;
	int numA,numB;
	for(int i=0;i<numTestes;i++){
		cin>>numA>>numB;
		
		int resu=testeBFS(numA, numB);
		cout<<resu<<endl;
	}
	
	return 0;
}

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
int testeBFS(int a, int b){
	int invert,increment;
	deque <int> fila;
	int visitados[110000]={0};
	int distancia[110000]={0};
	fila.push_back(a);
	visitados[a]=1;
	distancia[a]=0;
	if(a==b)
		return 0;
	while(1){
		//getchar();
		a = fila.front();
		fila.pop_front();
		invert = inverte(a);
		increment = a+1;
		//cout << "Retirou " << a << endl;
		if(invert==b || increment==b){
			break;
		}
		if(visitados[increment]==0){
			//cout << "explorando " << increment << endl;
			fila.push_back(increment);
			visitados[increment]=1;
			distancia[increment]=distancia[a]+1;
		}
		if(visitados[invert]==0){
			//cout << "explorando " << invert << endl;
			fila.push_back(invert);
			visitados[invert]=1;
			distancia[invert]=distancia[a]+1;
		}
	}
	return distancia[a]+1;
}
