/*3) Construa um programa que armazene nome, matrícula e média de
até N alunos e dê ao usuário a possibilidade de ver a listagem dos
alunos em ordem alfabética ou em ordem de classificação. Obs: uma
vez que os dados sejam digitados, o usuário deve poder ver as listagens
quantas vezes ele desejar.*/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[50];
    int matricula;
    float media;
} Aluno;

void listarAlunos(Aluno *lista, int tamanhoLista){
    printf("\n-----LISTAGEM DE Alunos-----"); 
    for(int i = 0; i < tamanhoLista; i++){
        printf("\n\n----------Aluno %d----------", i+1);
        printf("\nNome: %s", lista[i].nome);
        printf("\nMatricula: %d", lista[i].matricula);
        printf("\nMédia: %.2f", lista[i].media);
        printf("\n----------------------------");
    }
}

void ListagemAlfabetica(Aluno *lista, int tamanhoLista){
    Aluno aux;

    for(int i = 0; i < tamanhoLista; i++){
        for(int j = 0; j < tamanhoLista - 1; j++){
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

void ListagemClassificacao(Aluno *lista, int tamanhoLista){
    Aluno aux;

    for(int i = 0; i < tamanhoLista; i++){
        for(int j = 0; j < tamanhoLista - 1; j++){
            if (lista[j].media < lista[j + 1].media) { 
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

int main(){
    int NAlunos, valor;
    Aluno *listaAluno = (Aluno *) malloc (NAlunos * sizeof(Aluno));
    if (listaAluno == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    printf("Insira a quantidade de alunos que deseja cadastar: ");
    scanf("%d", &NAlunos);

    getchar();
    
    printf("\n--------CADASTRO DE ALUNOS--------");
    for(int i = 0; i < NAlunos; i++){
        printf("\n\nALUNO %d", i+1);
        printf("\nNome: ");
        fgets(listaAluno[i].nome, sizeof(listaAluno[i].nome), stdin);
        size_t len = strlen(listaAluno[i].nome);
            if (len > 0 && listaAluno[i].nome[len - 1] == '\n') {
                listaAluno[i].nome[len - 1] = '\0';
            }
        
        printf("\nMatricula: ");
        scanf("%d", &listaAluno[i].matricula);

        printf("\nMedia: ");
        scanf("%f", &listaAluno[i].media);
        
        getchar();
    }

    do {
        printf("\nDeseja ver a lista organizada em ordem alfabetica(1) ou por classificação(2)?\n");
        printf("Digite 0 para sair.\n");
        scanf("%d", &valor);
        getchar();

        switch (valor) {
            case 1:
                ListagemAlfabetica(listaAluno, NAlunos);
                listarAlunos(listaAluno, NAlunos);
                break;
            case 2:
                ListagemClassificacao(listaAluno, NAlunos);
                listarAlunos(listaAluno, NAlunos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (valor != 0);

    free(listaAluno);

    return 0;
}