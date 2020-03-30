#include <iostream>
#include <vector>
#include <string>
int ** alocaMatriz(int quantLinhas, int quantColunas);
int dfsSimples (int ** m, int vertice, int quantVertices, int * s );
int temCiclo (int ** m,int * s, int quantVertices);
using namespace std;
int main(int argc, char** argv) {
	int numCasos;
	cin>>numCasos;//recebe o numero de casos de testes
	int numDocs, numDepend;
	int linha,coluna;
	vector <string> resp;
	for(int i = 0;i<numCasos;i++){
		cin>>numDocs>>numDepend; // recebe o numero de documentos e dependencias
		int ** m = alocaMatriz(numDocs+1,numDocs+1);
		for(int j=0;j<numDepend;j++){ //'seta' cada dependencia na matriz
			cin>>linha>>coluna;
			m[linha][coluna]=1;
		}
		int * s = new int[numDocs+1]; //array que diz se o vertice foi visitado ou não pode ser 0, 1, 2
		int resu = temCiclo(m,s,numDocs); // chama a função de verificação que retorna se tem ciclo(1)
		if (resu==1)
			cout<<"SIM"<<endl; 
			//resp.push_back("SIM");
		else
			cout<<"NAO"<<endl;
			//resp.push_back("NAO");
	}
	/*
	for(int i = 0;i<numCasos;i++){
		cout<<resp[i]<<endl;
	}*/
	return 0;
}
int ** alocaMatriz(int quantLinhas, int quantColunas){ //aloca matriz[quantLinhas][quantColunas] = {0}
	
   int ** f = new int *[quantLinhas];
   for(int n = 0; n <quantLinhas; n++) {
       f[n] = new int[quantColunas];
		for(int j =0;j<quantColunas;j++){
			f[n][j]=0;
		}	
	}
	
	return f;
}
//para os codigos de DFSsimples e temCiclo: 0 = BRANCO; 1 = CINZA; 2 = PRETO
int dfsSimples (int ** m, int vertice, int quantVertices, int * s ) { //DFS simples, sem contagem de tempo
   for (int i = 1; i<=quantVertices; i++) {
	    if(m[vertice][i]==1){
		  if (s[i] == 2) continue;
	      if (s[i] == 1){
	      	s[i]=2;
			return 1;
		  }  
	      s[i] = 1;
	      if (dfsSimples(m,i,quantVertices,s) == 1) return 1;
		}
   }
   s[vertice] = 2;
   return 0;
}
int temCiclo (int ** m,int * s, int quantVertices) { //Usa DFS para verificar se tem ciclos
   for (int i = 1; i <=quantVertices; i++)
      s[i]=0;
   for (int i = 1; i <=quantVertices; i++) {  
      if (s[i] == 2) continue;
      s[i] = 1;
      if (dfsSimples(m,i,quantVertices,s) == 1) return 1;
   }
   return 0;
}

