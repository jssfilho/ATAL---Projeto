//
// Created by joao on 31/05/19.
//
#include "Auxiliar.h"

using namespace cv;
using namespace std;

int pai(int i){
    return i/2;
}

int filhoEsquerda(int i){
    return 2*i;
}

int filhoDireita(int i){
    return 2*i + 1;
}

Heap * heap_cria(){
    Heap * h = new Heap;
    h->n=0;
    return h;
}

void troca(Heap * h,int i, int j){
    No * no=h->lista[i];
    h->lista[i]=h->lista[j];
    h->lista[j] = no;
}
void corrigeDescendo(Heap *h,int i=0) {//  heapify(i)
    //repete enquanto i ainda tiver filho
    while (filhoEsquerda(i) < h->n)
    {
        //seleciona o filho com menor frequencia
        int filho = filhoEsquerda(i);
        if (filhoDireita(i) < h->n && h->lista[filhoDireita(i)]->prob <= h->lista[filhoEsquerda(i)]->prob)
            filho = filhoDireita(i);

        //Se o valor do pai é menor do que o valor do menor filho
        if (h->lista[i]->prob<= h->lista[filho]->prob)
            break;

        //caso contrario, trocamos o pai com o filho no heap e corrigimos agora para o filho
        troca(h,i,filho);
        i = filho;
    }
}

void push(Heap * h,int valor, int prob){
    No * no = new No;
    no->prob=prob;
    no->valor=valor;
    no->direito=NULL;
    no->esquerdo=NULL;
    h->lista[h->n]=no;
    h->n+=1;
    int n = h->n-1;
    //corrige subindo
    while (h->lista[n]->prob<h->lista[pai(n)]->prob){
        troca(h,n,pai(n));
        n = pai(n);
    }
}

No * get(Heap * h){
    No * no;
    if (h->n > 1)
    {
        troca(h,0, h->n-1);
        no = h->lista[h->n-1];
        h->n-=1;
        corrigeDescendo(h);
    } else if (h->n == 1) {
        h->n -= 1;
        no = h->lista[0];
    }
    return no;
}

void put(Heap * h,No * no){
    h->lista[h->n] = no;
    h->n+=1;
//    h->lista[h->n-1].prob = no->prob;
//    h->lista[h->n-1].direito = no->direito;
//    h->lista[h->n-1].esquerdo = no->esquerdo;
    //corrigeSubindo
    int n = h->n-1;
    while (h->lista[n]->prob<h->lista[pai(n)]->prob){
        troca(h,n,pai(n));
        n = pai(n);
    }
}
//cria arvore de huffman
No * raizTree(int * array_frequencias){
    Heap * h = heap_cria();
    for(int i=0;i<MAX_ARRAY;i++){
        push(h,i,array_frequencias[i]);
    }
    while(h->n>1){
        No * no = new No; //cria novo no
        No * e = get(h);//pega minimo do heap
        No * d = get(h);//pega segundo minimo do heap
        no->prob = e->prob + d->prob; //novo no recebe a soma da probabilidade dos minimos
        no->esquerdo= e;
        no->direito= d;
        put(h,no);
    }
    return get(h);
}
//gera um mapa de codigos onde indice vai de 0 a 255 e os valores são string de tamanho variados representando cada valor
int huffmanGeraCode(No * raiz,string code,string * mapa){
    //caso seja o ultimo nó(folha) achou o valor
    if(raiz->direito==NULL && raiz->esquerdo==NULL){
        mapa[raiz->valor]=code;
        return -1;
    }
    code.append("0");
    huffmanGeraCode(raiz->esquerdo,code,mapa);
    code.pop_back();

    code.append("1");
    huffmanGeraCode(raiz->direito,code,mapa);
    code.pop_back();
}
// função que transforma um inteiro em uma cadeia de caracteres 0 ou 1 (binario)
string transIntBin(int i){
    string binCode="";
    while (i>0){
        if(i==1){
            binCode.push_back('1');
        }else if(i%2==0 && i!=0){
            binCode.push_back('0');
        }else if(i%2==1){
            binCode.push_back('1');
        }
        i=i/2;
    }
    while(binCode.length()<QUANT_BITS) {
        binCode.push_back('0');
    }
    return binCode;
}
string transIntBinWithNumBit(int i,int tamPalavra){
    string binCode="";
    while (i>0){
        if(i==1){
            binCode.push_back('1');
        }else if(i%2==0 && i!=0){
            binCode.push_back('0');
        }else if(i%2==1){
            binCode.push_back('1');
        }
        i=i/2;
    }

    while(binCode.length()<tamPalavra) {
        binCode.push_back('0');
    }
    string binCodeFinal="";
    for(int i=binCode.length()-1;i>=0;i--){
        binCodeFinal.push_back(binCode[i]);
    }
    return binCodeFinal;
}

//essa função recebe os caracteres do arquivo comprimido e retorna sua versão com cada bit sendo "0" ou "1"
string makeEncodeCode(string code){
    string  encode="";
    int tam = code.length();
    for(int k = 0;k<tam;k++){
        uint8_t inteiro = (uint8_t) code[k];
        string bins = transIntBin(inteiro);
        for(int j=bins.length()-1;j>=0;j--){
            encode.push_back(bins[j]);
        }
    }

    return encode;
}
//função responsavel por decodificar a mensagem codificada em uma imagem
Mat huffmanDecode(string encode,No * raiz,int altura,int largura){
    //raizOriginal fica salva para retorno a cada no final encontrado
    No * raizTrue = raiz;
    int count_altura=0;
    int count_largura=0;
    Mat img(altura,largura,CV_8UC1);
    for(int k=0;k<encode.length();k++){
        if (encode[k]=='1')
            raiz = raiz->direito;
        if (encode[k]=='0')
            raiz = raiz->esquerdo;
        if(raiz->direito==NULL && raiz->esquerdo==NULL){
            img.at<uchar>(count_altura,count_largura)= (uchar) raiz->valor;
            count_largura++;
            if(count_largura==largura){
                count_altura++;
                count_largura=0;
            }
            raiz=raizTrue;
        }
    }
    return img;
}