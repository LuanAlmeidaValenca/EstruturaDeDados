#include <stdio.h>

int main(){
    int somatorio = 0, tamanho;

    printf("Insira até qual número deseja somar a partir de 1: ");
    scanf("%d", &tamanho);

    for(int i = 1; i <= tamanho; i++){
        somatorio += i;
    }

    printf("\nSomatório: %d", somatorio);

    return 0;
}