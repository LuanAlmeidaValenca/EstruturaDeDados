//Aluno: Luan Almeida Valença

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int CPF, posicao;
    char nome[30];
    struct node *proximo;
} Node;

typedef struct{
    Node *inicio;
    Node *fim;
    int tamanho;

} Lista;

void criarLista (Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho  = 0;

    printf("\nLista criada com sucesso!\n");
}

void imprimirLista(Lista *lista){
    if (lista->tamanho == 0){
        printf("\nLista vazia\n");
    }else{
    Node *node = lista->inicio;
    if(node){
        do{
            printf("-------------------");
            printf("\nCPF: %d", node->CPF);
            printf("\nNome: %s", node->nome);
            printf("-------------------\n");
            node = node->proximo;
        }while (node !=lista->inicio);    
    }
    }
}

void inserirNoInicio(Lista *lista, int CPFid, char nome[30]){
    Node *novo = malloc(sizeof(Node));
    if (!novo){
        printf("Erro na alocação de memória\n");
        return;
    }

    novo->CPF = CPFid;
    strcpy(novo->nome, nome);

    novo->proximo = lista->inicio;
    lista->inicio = novo;

    if(lista->fim == NULL){ //caso a lista esteja vazia
        lista->fim = novo;
    }
    lista->fim->proximo = lista->inicio;
    lista->tamanho++;

}

void inserirNoFinal(Lista *lista, int CPFid, char nome[30]){
    Node *novo = malloc(sizeof(Node));
    if (!novo){
        printf("Erro na alocação de memória\n");
        return;
        }
        
    novo->CPF = CPFid;
    strcpy(novo->nome, nome);

    if (lista->inicio == NULL){ //caso a lista esteja vazia
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->proximo = lista->inicio;

    }else{
        lista->fim->proximo = novo;
        lista->fim = novo;
        novo->proximo = lista->inicio;
    }
    lista->tamanho++;
}

void inserirEmLugarEspecifico(Lista *lista, int CPFid, char nome[30], int posicao){
    Node *novo = malloc(sizeof(Node));
    if (!novo){
        printf("Erro na alocação de memória\n");
        return;
        }
        
    novo->CPF = CPFid;
    strcpy(novo->nome, nome);
    
    if (lista->inicio == NULL){ //caso a lista esteja vazia
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->proximo = lista->inicio;

    } else if (posicao <= 0) { //caso o valor seja menor ou igual a 0, posiciona no começo da lista
        inserirNoInicio(lista, CPFid, nome);
        free(novo);
    } else if (posicao > lista->tamanho){ //caso o valor seja maior que o tamanho, insere no final
        inserirNoFinal(lista, CPFid, nome);
        free(novo);
    } else{
    Node* temp = lista->inicio;
    for (int i = 1; i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    novo->proximo = temp->proximo;
    temp->proximo = novo;
    }
    
}


void removerNoInicio(Lista *lista){
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Node *temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->fim->proximo = lista->inicio;
    free(temp);
    lista->tamanho--;
}

void removerNoFinal(Lista *lista){
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    if (lista->inicio == lista->fim) { //caso haja apenas um nó
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        return;
    }
    Node *temp = lista->inicio;
    while (temp->proximo != lista->fim) {
        temp = temp->proximo;
    }

    free(lista->fim);
    lista->fim = temp;
    lista->fim->proximo = lista->inicio;
    lista->tamanho--;
}

void removerEmLugarEspecifico(Lista *lista, int posicao){
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    if (posicao <= 0) {
        removerNoInicio(lista);
        return;
    }
    
    if (posicao >= lista->tamanho - 1) {
        removerNoFinal(lista);
        return;
    }

    Node *temp = lista->inicio;
    for (int i = 1; i < posicao; i++) {
        temp = temp->proximo;
    }
    
    Node *remover = temp->proximo;
    temp->proximo = remover->proximo;
    
    if (remover == lista->fim) {
        lista->fim = temp;
    }
    
    free(remover);
    lista->tamanho--;
}

void sorteio(Lista *lista){

    if(lista->tamanho <= 1){
        printf("Lista vazia ou possui apenas 1 concorrente, impossivel de realizar o sorteio");
        return;
    }

    while (lista->tamanho > 1) {
        int random = rand() % lista->tamanho;
        printf("Eliminando concorrente na posição: %d\n", random);
        removerEmLugarEspecifico(lista, random);
        imprimirLista(lista);
        system("pause");
    }

    printf("O vencedor foi: %s (CPF: %d)\n", lista->inicio->nome, lista->inicio->CPF);
    
}

void mudarInicioFim(Lista *lista) {
    if (lista->inicio == NULL || lista->inicio == lista->fim) {
        printf("A lista está vazia ou tem apenas um elemento.\n");
        return;
    }

    lista->inicio = lista->inicio->proximo;
    lista->fim = lista->fim->proximo;
    lista->fim->proximo = lista->inicio;
}

void liberarLista(Lista *lista) {
    if (lista->inicio == NULL) {
        return;  // Lista já está vazia
    }

    Node *atual = lista->inicio;
    Node *proximo;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != lista->inicio);

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int main (){
    int escolha, CPF, pos;
    char nome[30];
    Lista lista;

    while(escolha != 10){

    system("cls");

    printf("\nEscolha a opcao desejada: \n");
    printf("1 - Criar lista\n");
    printf("2 - Ver lista\n");
    printf("3 - Adicionar participante no inicio da lista\n");
    printf("4 - Adicionar participante no final da lista\n");
    printf("5 - Adicionar participante em algum lugar especifico da lista\n");
    printf("6 - Remover participante do inicio da lista\n");
    printf("7 - Remover participante do fim da lista\n");
    printf("8 - Remover participante em algum lugar especifico da lista\n");
    printf("9 - Iniciar sorteio\n");
    printf("10 - Finalizar execucao\n\n");
    scanf("%d", &escolha);
    fflush(stdin);

        switch (escolha){
        case 1:
            criarLista(&lista);
            system("pause");
            break;
        case 2:
            imprimirLista(&lista);
            system("pause");
            break;
        case 3:
            printf("\nInsira o nome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            fflush(stdin);
            printf("\nInsira o CPF do cliente: ");
            scanf("%d", &CPF);
            fflush(stdin);
            inserirNoInicio(&lista, CPF, nome);
            system("pause");
            break;
        case 4:
            printf("\nInsira o nome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            fflush(stdin);
            printf("\nInsira o CPF do cliente: ");
            scanf("%d", &CPF);
            fflush(stdin);
            inserirNoFinal(&lista, CPF, nome);
            system("pause");
            break;
        case 5:
            printf("\nInsira o nome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            fflush(stdin);
            printf("\nInsira o CPF do cliente: ");
            scanf("%d", &CPF);
            fflush(stdin);
            printf("\nInsira a posição que deseja colocar: ");
            scanf("%d", &pos);
            fflush(stdin);
            inserirEmLugarEspecifico(&lista, CPF, nome, pos);
            system("pause");
            break;
        case 6:
            removerNoInicio(&lista);
            system("pause");
            break;
        case 7:
            removerNoFinal(&lista);
            system("pause");
            break;
        case 8:
            printf("Insira a posição que deseja remover o concorrente: ");
            scanf("%d", &pos);
            removerEmLugarEspecifico(&lista, pos);
            system("pause");
            break;
        case 9:
            sorteio(&lista);
            system("pause");
            break;
        case 10:
            liberarLista(&lista);
            printf("Finalizando...\n\n");
            return 1;
            break;

        default:
            break;
        }
    }

    return 0;
}