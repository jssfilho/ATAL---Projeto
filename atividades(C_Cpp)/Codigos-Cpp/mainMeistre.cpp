#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int ** alocaMatriz(int quantLinhas, int quantColunas);
int backTrack(string * mapa,int ** refMat ,int x,int y,int maxLine, int maxCol,char ult);
int main(int argc, char** argv) {
	int quantLinhas,quantColunas;
	cin>>quantColunas;
	cin>>quantLinhas;
	string * mapa = new string[quantLinhas];
	for(int i =0;i<quantLinhas;i++){
		cin>>mapa[i];
	}
	int ** refMat = alocaMatriz(quantLinhas,quantColunas);
	char c='.';
	int resu = backTrack(mapa,refMat,0,0,quantLinhas,quantColunas,c);
	if(resu==1)
		cout<<"*"<<endl;
	if(resu==0)
		cout<<"!"<<endl;
	return 0;
}
int backTrack(string * mapa,int ** refMat ,int x,int y,int maxLine, int maxCol,char ult){
	int ret;
    refMat[x][y]=1;
    if (mapa[x][y]=='^' || mapa[x][y]=='>' || mapa[x][y]=='<' || mapa[x][y]=='v'){
		ult=mapa[x][y];
	}
	if ( mapa[x][y]=='*')
		return 1;
  	else if (x>0 && ult=='^' && refMat[x-1][y]==0){
		ret = backTrack(mapa,refMat,x-1,y,maxLine,maxCol,ult);
  	}
  	else if (y>0 && ult=='<' && refMat[x][y-1]==0){
		ret = backTrack(mapa,refMat,x,y-1,maxLine,maxCol,ult);
  	}
  	else if (x<maxLine-1 && ult=='v' && refMat[x+1][y]==0){
		ret = backTrack(mapa,refMat,x+1,y,maxLine,maxCol,ult);
  	}
  	else if (y<maxCol-1 && ult=='>' && refMat[x][y+1]==0){
		ret = backTrack(mapa,refMat,x,y+1,maxLine,maxCol,ult);
  	}
  	else //if (refMat[x-1][y]==1 || refMat[x][y-1]==1 || refMat[x+1][y]==1 || refMat[x][y+1]==1)
  		return 0;
	return ret;
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
