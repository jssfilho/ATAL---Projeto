#ifndef HUFFIMAN_ARVORE_H
#define HUFFIMAN_ARVORE_H

#endif //HUFFIMAN_ARVORE_H

#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#define MAX_ARRAY 256       //tamanho do vetor de frequencias
#define QUANT_BITS_TAM_IMG 16 //TAMANHO DE BIT PARA ARMAZENAR A ALTURA E LARGURA DA IMAGEM
#define QUANT_BITS_TAM_FREQ 32 //QUANTIDADE DE BITS PARA REPRESENTAR A FREQUENCIA
#define QUANT_BITS 8 //QUANTIDADE DE BITS DEFAULT
using namespace cv;
using namespace std;
typedef struct No No;
struct No{
    int prob;
    int valor;
    No * esquerdo;
    No * direito;
};

struct Heap{
    int n;
    No * lista[MAX_ARRAY];
};

Heap * heap_cria();

No * get(Heap * h);

void push(Heap * h,int valor, int prob);

No * raizTree(int * array_frequencias);

int huffmanGeraCode(No * raiz,string code,string * mapa);

Mat huffmanDecode(string encode,No * raiz,int altura,int largura);

string makeEncodeCode(string code);

string transIntBin(int i);

string transIntBinWithNumBit(int i,int tamPalavra);