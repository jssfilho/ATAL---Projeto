#include <iostream>
#include <queue>
#include <math.h>
#define INF 10e8


using namespace std;
typedef pair<int,int> ii;
int dijkstra(int ** m,int quantVertices, int ini, int fim);
int ** alocaMatriz(int quantLinhas, int quantColunas);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
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
			if(m[v][i]>0){
				if((d[i]>d[v]+m[v][i])){
					d[i]=d[v]+m[v][i];
					pq.push(make_pair(d[i],i));
				}
			}	
		} 
	}
	return d[fim];
}
