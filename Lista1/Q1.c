/*1)Guarde N números em um vetor alocado dinamicamente. Exiba a
média dos números lidos e os múltiplos de 6 digitados. */

#include <stdio.h>

int main(){

    int *vetor, numero, somatorio = 0, qntdMultiplo6 = 0;

    printf("Digite a quantidade de números N: ");
    scanf("%d", &numero);

    vetor = (int*) malloc(numero * sizeof(int));

    printf("\nInsira os numeros a seguir");

    for(int i = 0; i<numero; i++){
        printf("\nNumero %d: ", i+1);
        scanf("%d", &vetor[i]);
        somatorio += vetor[i];
    }


    float media = (float)somatorio/numero;
    printf("\n Média dos valores: %.2f", media);

    for(int i = 0; i<numero; i++){
        if(vetor[i]%6 == 0){
            qntdMultiplo6++;
        }
    }

    printf("\n Quantidade de numeros multiplo de 6: %d", qntdMultiplo6);

    return 0;
} 