#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int ** alocaMatriz(int quantLinhas, int quantColunas);

void percorrerComponente(int indice,int ** m, int quantVertices,int * cor);
int quantComponentes(int ** m, int quantVertices);
using namespace std;
int main(int argc, char** argv) {
	int quantCasos;
	cin>>quantCasos;
	for(int i=0;i<quantCasos;i++){
		int quantVertices,quantArestas;
		cin>>quantVertices;
		cin>>quantArestas;
		int ** m= alocaMatriz(quantVertices+1,quantVertices+1);
		int v1,v2;
		for(int j=0;j<quantArestas;j++){
			cin>>v1>>v2;
			m[v1][v2]=1;
			m[v2][v1]=1;
		}
		int resu;
		if(quantArestas==0)
			resu = quantVertices;
		else
			resu = quantComponentes(m,quantVertices+1);
			
		//cout<<resu<<"--"<<endl;
		
		if (resu==1)
			cout<<"Caso #"<<i+1<<": a promessa foi cumprida"<<endl;
		else
			cout<<"Caso #"<<i+1<<": ainda falta(m) "<<resu-1<<" estrada(s)"<<endl;
			
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
int * dfs (int inicio, int ** matrizAd,int quantVertices){
	int *cor = new int[quantVertices];
	tempo =0;
	int * f = new int[quantVertices];
	for(int i=0;i<quantVertices;i++){
		cor[i]=0;
		f[i]=0;
	}
	for(int i=0;i<quantVertices;i++){
		if(cor[i]==0)
			dfs_visit(i, matrizAd,cor,quantVertices,f);
	}
	return f;
}
void dfs_visit(int vertice,int ** matAdj,int * cor,int quantVertices,int * f){
	cor[vertice]=1;
	tempo+=1;
	for(int i= 0;i<quantVertices;i++){
		if(matAdj[vertice][i]==1 && cor[i]==0){
			dfs_visit(i,matAdj,cor,quantVertices,f);
		}		
	}
	cor[vertice]=2;
	tempo+=1;
	f[vertice]=tempo;
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
	return cont-1;
}
