#include "Auxiliar.h"
using namespace std;
using namespace cv;

int main() {
    Mat img;
    //imagem 1 4k
    //img = imread("/home/joao/CLionProjects/huffman/Image/LEFT_4k3d_2160p24_010512.tif",IMREAD_GRAYSCALE);
    //imagem 2 4k
    img = imread("../Image/LEFT_4k3d_2160p24_003900.tiff",IMREAD_GRAYSCALE);


    int largura = img.size().width;
    int altura = img.size().height;
    int  array_frequencias[MAX_ARRAY] = {0};

    int a;
    for(int i = 0; i<altura;i++) {
        for (int j = 0; j < largura; j++) {
            a = (int) img.at<uchar>(i, j);
            array_frequencias[a] += 1;
        }
    }
    //gerar arvore de huffman
    No * raiz = raizTree(array_frequencias);

    //gerar mapa de codigos
    string code="";
    string * mapa = new string[MAX_ARRAY];
    huffmanGeraCode(raiz,code,mapa);



    //gerar o arquivo compactado
    ofstream ofile;
    //pode ser alteradoo nome do arquivo compactado o default é image
    ofile.open("../CompressImage/image.bin",ios::binary);

    string encodeMsg = "";
    //tentativa de colocar no arquivo compactado: altura,largura,e array de frequencias
    /*
    string alturaBin = transIntBinWithNumBit(altura,QUANT_BITS_TAM_IMG);
    string larguraBin = transIntBinWithNumBit(largura,QUANT_BITS_TAM_IMG);
    for(int j=0;j<QUANT_BITS_TAM_IMG;j++){
        encodeMsg.push_back(alturaBin[j]);
    }
    for(int j=0;j<QUANT_BITS_TAM_IMG;j++){
        encodeMsg.push_back(larguraBin[j]);
    }
    for(int i=0;i<MAX_ARRAY;i++){
        string bitFreq = transIntBinWithNumBit(array_frequencias[i],QUANT_BITS_TAM_FREQ);
        for(int j=0;j<bitFreq.length();j++){
            encodeMsg.push_back(bitFreq[j]);
        }
    }
    */

    //gerar cadeia de caracteres substituindo cada valor de pixel por seu codigo;
    unsigned  char tmp=0;
    for(int i = 0; i<altura;i++) {
        for (int j = 0; j < largura; j++) {
            a = (int) img.at<uchar>(i, j);
            string tmpString = mapa[a];
            for(int k =0;k<tmpString.length();k++){
                encodeMsg.push_back(tmpString[k]);
            }
        }
    }
    //transforma cada conjunto de 8 caracteres(0 ou 1) em um caractere

    int count=0;
    int total = encodeMsg.length()/QUANT_BITS;
    string mensagemImagem = "";
    char * buffer2 = new char[total];
    unsigned char carac= 0;
    for(int i = 0; i<total;i++) {
        for (int j = 0; j < QUANT_BITS; j++) {
            if(encodeMsg[count]=='0'){
                carac=carac<<1;
            }else if(encodeMsg[count]=='1'){
                carac=carac<<1;
                carac=carac|0b00000001;
            }
            count++;
        }
        buffer2[i]=carac;
        mensagemImagem.push_back(carac);
        carac=0;
    }



    ofile.write(buffer2, total);
    ofile.close();
    //ler e descompactar
    /*
    int contador=0;
    for(int i=0;i<QUANT_BITS_TAM_IMG;i++){

    }
    for(int i=0;i<QUANT_BITS_TAM_IMG;i++){

    }
    */
    //decodifica em imagem a mensagem escrita no arquivo .bin
    string b = makeEncodeCode(mensagemImagem);
    Mat imgDesc = huffmanDecode(b,raiz,altura,largura);
    imwrite("../ImagensReconstruidas/LEFTDesc.tiff",imgDesc);
    return 0;

}

