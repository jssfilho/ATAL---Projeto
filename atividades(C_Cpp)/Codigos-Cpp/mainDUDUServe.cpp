#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ** alocaMatriz(int quantLinhas, int quantColunas);

void percorrerComponente(int indice,int ** m, int quantVertices,int * cor);
int quantComponentes(int ** m, int quantVertices);
using namespace std;
int main(int argc, char** argv) {
	int numCasos;
	cin>>numCasos;//recebe o numero de casos de testes
	int numDocs, numDepend;
	int linha,coluna;
	for(int i = 0;i<numCasos;i++){
		cin>>numDocs>>numDepend; // recebe o numero de documentos e dependencias
		int ** m = alocaMatriz(numDocs+1,numDocs+1);
		for(int j=0;j<numDepend;j++){ //'seta' cada dependencia na matriz
			cin>>linha>>coluna;
			m[linha][coluna]=1;
		}
		//int * s = new int[numDocs+1]; //array que diz se o vertice foi visitado ou não pode ser 0, 1, 2
		int resu = quantComponentes(m,numDocs);
		if(resu<numDocs)
			cout<<"SIM"<<endl;
		else
			cout<<"NAO"<<endl;
	}
	return 0;
}
int ** alocaMatriz(int quantLinhas, int quantColunas){
	
   int ** f = new int *[quantLinhas];
   for(int n = 0; n < quantLinhas; n++) {
       f[n] = new int[quantColunas];
		for(int j =0;j<quantColunas;j++){
			f[n][j]=0;
		}	
	}
	
	return f;
}
void percorrerComponente(int indice,int ** m, int quantVertices,int * cor){
	cor[indice]=1;
	for(int i=0;i<quantVertices;i++){
		if(m[indice][i]==1 && cor[i]!=1){
			percorrerComponente(i,m,quantVertices,cor);
		}
	}
}
int quantComponentes(int ** m, int quantVertices){
	int * cor = new int[quantVertices];
	for(int i=0;i<quantVertices;i++){
		cor[i]=0;
	}
	int cont =0;
	for(int i=0;i<quantVertices;i++){
		if(cor[i]!=1){
			cont+=1;
			percorrerComponente(i,m,quantVertices,cor);
		}
			
	}
	return cont;
}
