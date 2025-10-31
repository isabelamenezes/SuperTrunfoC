#include <stdio.h>

int main() {
   
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("Movimento da torre:\n");
    for (int i = 1; i <= casasTorre; i++) 
        printf("direita\n");

    printf("Movimento do bispo:\n");
    int i = 1;
    while (i <= casasBispo) {
        printf("Cima, Direita\n");
        i++;
    }
    
    printf("Movimento da rainha:\n");
    int j = 1;
    do {
        printf("esquerda\n");
        j++;
    } while ("j <= casasRainha");
    

    return 0 ;

}