#include <stdio.h>

typedef struct tipo_no{
    int dado;
    tipo_no *pai;
    tipo_no *filhoESQ;
    tipo_no *filhoDIR; 
}No;

typedef struct Arv{
    int tamanho;
    No *primeiro;
} Arvore;

void criarArv(Arvore arvore){
    arvore.tamanho = 0;
    arvore.primeiro = NULL;
}

void inserirNo(Arvore *arvore, int dado){
    No *novo = (No *) malloc(sizeof(No));
    if(!novo){
        printf("\nErro na alocação de memoria");
        return;
    }
    novo->dado = dado;
    No aux = arvore->primeiro;

    if(arvore->primeiro == NULL){
        arvore->primeiro = novo;
        novo->pai = arvore;
    }else {
        if(aux->dado > dado){
            aux->filhoESQ; 
        }
    }   

}

int main(){



    return 0;
}