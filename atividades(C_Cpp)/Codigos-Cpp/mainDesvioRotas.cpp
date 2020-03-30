#include <iostream>
#include <queue>
#include <math.h>
#define INF 10e8


using namespace std;
typedef pair<int,int> ii;
int dijkstra(int ** m,int quantVertices, int ini, int fim);
int ** alocaMatriz(int quantLinhas, int quantColunas);
int main(int argc, char** argv) {
	int N,M,C,K;
	int peso,linha,coluna;
	cin>>N>>M>>C>>K;
	int ** m = alocaMatriz(N,N);
	while(N!=0 && M!=0 && C!=0 && K!=0){
		m = alocaMatriz(N,N);
		for(int i=0;i<M;i++){
			cin>>linha>>coluna>>peso;
			if(linha>(C-1) && coluna>(C-1)){
				m[linha][coluna]=peso;
				m[coluna][linha]=peso;
			}else if((linha<=(C-1) && coluna<=(C-1)) && abs(linha-coluna)<2){
				m[linha][coluna]=peso;
				m[coluna][linha]=peso;
		 	}else if((linha<=(C-1) && coluna>(C-1))){
				//m[linha][coluna]=peso;
				m[coluna][linha]=peso;
			}else if(linha>(C-1) && coluna<=(C-1)){
				m[linha][coluna]=peso;
			}
		}
		cout<<dijkstra(m,N,K,C-1)<<endl;
		cin>>N>>M>>C>>K;
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

int dijkstra(int ** m,int quantVertices, int ini, int fim){
	int * d = new int[quantVertices]; //array de distancias
	//int * p = new int[quantVertices];
	for(int i=0;i<quantVertices;i++){
		d[i]=INF; //inicializa cada posição
	}
	priority_queue <ii> pq;
	pq.push(make_pair(0,ini));
	d[ini]=0;
	while(!pq.empty()){
		ii valor = pq.top();
		pq.pop();
		int v = valor.second;
		//if(v==fim) break;
		//if(d[v]<valor.first) continue;
		for(int i=0;i<quantVertices;i++){
			if(m[v][i]>0 || m[i][v]>0){
				if((d[i]>d[v]+m[v][i])){
					d[i]=d[v]+m[v][i];
					pq.push(make_pair(d[i],i));
				}
			}	
		} 
	}
	return d[fim];
}
