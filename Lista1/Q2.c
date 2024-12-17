#include <stdio.h>
#include <stdlib.h>

typedef struct 
    {
        char nome[50];
        int idade;
        float peso;

    } Atletas;

void listarAtletas(Atletas *lista, int tamanhoLista){
    printf("\n-----LISTAGEM DE ATLETAS-----"); 
    for(int i = 0; i < tamanhoLista; i++){
        printf("\n\n----------ATLETA %d----------", i+1);
        printf("\n Nome: %s", lista[i].nome);
        printf("\nIdade: %d anos", lista[i].idade);
        printf("\nPeso: %.2fkg", lista[i].peso);
        printf("\n----------------------------");
    }
}

void CalcMediaPesos(Atletas *lista, int tamanhoLista){
    float mediaPesos, somatorio = 0;;

    for(int i = 0; i < tamanhoLista; i++){
        somatorio += lista[i].peso;
    }
    mediaPesos = somatorio/(float) tamanhoLista;
    printf("Media dos pesos dos atletas: %.2f\n\n", mediaPesos);
}

void QNTDMenoresIdade(Atletas *lista, int tamanhoLista){
    int NMenores = 0;
    for(int i = 0; i < tamanhoLista; i++){
        if(lista[i].idade < 18){
            NMenores++;
        }
    }
    printf("Quantidade de menores de idade: %d", NMenores);
}

int main(){

    int NAtletas;

    printf("Insira quantos atletas serão cadastrados: ");
    scanf("%d", &NAtletas);

    getchar();

    Atletas *listaAtletas = (Atletas *) malloc (NAtletas * sizeof(Atletas));

    if (listaAtletas == NULL) {
         printf("\nErro na alocação de memoria!");    
        return 1;
    }
    printf("\n------CADASTRO DE ATLETAS------");
    for(int i = 0; i < NAtletas; i++){
    printf("\n\nATLETA %d", i+1);
    printf("\nNome: ");
    fgets(listaAtletas[i].nome, sizeof(listaAtletas[i].nome), stdin);
    size_t len = strlen(listaAtletas[i].nome);
        if (len > 0 && listaAtletas[i].nome[len - 1] == '\n') {
            listaAtletas[i].nome[len - 1] = '\0';
        }
    
    printf("Idade: ");
    scanf("%d", &listaAtletas[i].idade);

    printf("Peso (em kg): ");
    scanf("%f", &listaAtletas[i].peso);
    
    getchar();
   }
    system("cls");

    CalcMediaPesos(listaAtletas, NAtletas);
    QNTDMenoresIdade(listaAtletas, NAtletas);
    listarAtletas(listaAtletas, NAtletas);

    return 0;
}