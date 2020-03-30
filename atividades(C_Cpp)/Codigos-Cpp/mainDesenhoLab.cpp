#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int ** alocaMatriz(int quantLinhas, int quantColunas);
int dfs (int inicio, int ** matrizAd,int quantVertices);
int dfs_visit(int vertice,int ** matAdj,int * cor,int quantVertices);

using namespace std;
int main(int argc, char** argv) {
	int quantCasos;
	cin>>quantCasos;
	for(int i=0;i<quantCasos;i++){
		int inicio;
		int quantVertices,quantArestas;
		cin>>inicio;
		cin>>quantVertices>>quantArestas;
		int ** m= alocaMatriz(quantVertices,quantVertices);
		int v1,v2;
		for(int j=0;j<quantArestas;j++){
			cin>>v1>>v2;
			m[v1][v2]=1;
			m[v2][v1]=1;
		}
		int tempo = dfs(inicio,m,quantVertices);
		cout<<tempo<<endl;
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
int dfs (int inicio, int ** matrizAd,int quantVertices){
	int *cor = new int[quantVertices];
	int tempo =0;
	for(int i=0;i<quantVertices;i++){
		cor[i]=0;
	}
	for(int i=0;i<quantVertices;i++){
		if(cor[i]==0)
			tempo += dfs_visit(i, matrizAd,cor,quantVertices);
	}
	return tempo;
}
int dfs_visit(int vertice,int ** matAdj,int * cor,int quantVertices){
	cor[vertice]=1;
	int tempo=0;
	
	for(int i= 0;i<quantVertices;i++){
		if(matAdj[vertice][i]==1 && cor[i]==0){
			tempo+=1;
			tempo += dfs_visit(i,matAdj,cor,quantVertices);
			tempo+=1;
		}		
	}
	cor[vertice]=2;
	return tempo;
}
