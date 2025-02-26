#include <stdio.h>
#include <stdlib.h>

//verificar "inserir em posiçao", "inserir ordenado" e "remover determinado dado", implementar um verificador para 
// saber se a lista esta ordenada, e so permitir a inserçao ordenada nesse caso 


typedef struct node_type {
    int data;
    struct node_type *next;
} Node;

typedef struct LIST {
    Node *first;
    Node *last;
    int size;
} List;

void startList(List *list){
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    printf("\nList sucesfully created");
}

void printList(List list){
    
    if(list.first == NULL){
        printf("\nEmpty list, nothing to print");
    }else{
        Node *temp = list.first;
        if(!temp){
            printf("\nMemory allocation error!");
            return;
        }
        int i = 1;
        while (temp != NULL){
            printf("\nData %d: %d", i, temp->data);
            temp = temp->next;
            i++;
        }
    }
    
    printf("\n");
}

int search(List *list, int data){
    printf("\nentrou na search");
    if(list->first == NULL){
        printf("\nEmpty list");
        return 0;
    }
    
    Node *searching = list->first;
    int find = 0;
    while(searching->next != NULL && searching->data != data){
        searching = searching->next; 
    }
    if(searching->data == data){
        printf("\nData find!");
        find = 1;
    } else {
        printf("\nData not find!");
        find = 0;
    }
    printf("\nsaiu da search");
    return find;
}

void addFirst(List *list, int data){
    Node *new = malloc(sizeof(Node));
    if(!new){
        printf("\nMemory allocation error!");
        return;
    }
    if(list->first == NULL){ //First node
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else{
        Node *temp = list->first;
        list->first = new;
        new->next = temp;
    }
    new->data = data;
    list->size++;
    printf("Node sucesfully added!");
}

void addLast(List *list, int data){
    Node *new = malloc(sizeof(Node));
    if(!new){
        printf("\nMemory allocation error!");
        return;
    }
    if(list->first == NULL){ //First node
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else{
        list->last->next = new;
        list->last = new;
        new->next = NULL;
    }
    new->data = data;
    list->size++;
    printf("Node sucesfully added!");
}

void addDeterminedPosition(List *list, int data){
    Node *new = malloc(sizeof(Node));
    if(!new){
        printf("\nMemory allocation error!");
        return;
    }
    
    int position;
    printf("\nInsert the position: ");
    scanf("%d", &position);

    if(position <= 1){
        free(new);
        addFirst(list, data);
    }else if(position > list->size){
        free(new);
        addLast(list, data);
    }else{
        Node *temp = list->first;
        for (int i = 1; i < position - 1; i++){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        new->data = data;
        list->size++;
    }
}

void ordenedInsert(List *list, int data){
    Node *new = malloc(sizeof(Node));
    if(!new){
        printf("\nMemory allocation error!");
        return;
    }
    
    if(list->first == NULL){ //First node
        addFirst(list, data);
        free(new);
    } else{
        Node *temp = list->first;
        while (temp->next->data < data && temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp->next == NULL){
            addLast(list, data);
        }else{
            new->next = temp->next;
            temp->next = new;
            new->data = data;
        }
        
    }
    list->size++;
}

void removeFirst(List *list){
    if(list->first == NULL){
        printf("\nThere's no node to remove!");
        return;
    }
    Node *remove = list->first;
    if(remove->next == NULL){ //Only one node in the list
        list->first = NULL;
        list->size = 0;
        free(remove);
    }else{
        list->first = remove->next;
        list->size--;
        free(remove);
    }
    printf("\nThe first node was sucesfully removed");
    list->size--;
}

void removeLast(List *list){
    if(list->first == NULL){
        printf("\nEmpty list");
        return;
    }

    Node *remove = list->last;
    if (list->first == list->last && list->first != NULL){//If the list has only 1 node
        list->first = NULL;
        list->last = NULL;
        free(remove);
        return;
    }

    Node *aux = list->first;

    while (aux->next != remove)
    {
        aux = aux->next;
    }
    aux->next = NULL;
    list->last = aux;
    list->size--;
    free(remove);
    printf("\nThe last node was sucesfully removed");
}

void removeDeterminedPosition(List *list){
    if(list->first == NULL){
        printf("\nEmpty list");
        return;
    }
    int position;
    printf("\nInsert the position: ");
    scanf("%d", &position);

    if(position >= list->size){
        removeLast(list);
        return;
    }
    if(position <= 1){
        removeFirst(list);
        return;
    }
    Node *remove = list->first->next;
    Node *aux = list->first;
    for(int i = 1; i < position - 1; i++){
        remove = remove->next;
        aux = aux->next;
    }
    aux->next = remove->next;
    free(remove);
    list->size--;
}

void removeDeterminedElement(List *list, int data){
    if(list->first == NULL){
        printf("\nEmpty list");
        return;
    }
    if(!search(list, data)){
        return;
    }
    Node *remove = list->first;
    Node *aux;
    while(remove->data != data){
        if(remove == list->first){
            aux = list->first;
        }else{
            aux = aux->next;
        }
        remove = remove->next;
    }
    if(list->first == remove){
        removeFirst(list);
        return;
    }
    if(list->last == remove){
        removeLast(list);
        return;
    }
    aux->next = remove->next;
    free(remove);
    list->size--;
}

void order(List *list){
    if(list->first == NULL){
        printf("\nEmpty list");
        return;
    }
    if(list->size == 1){
        printf("\nNot enough elements to order");
        return;
    }
    int swapped;
    Node *ptr1;
    Node *lptr = NULL; 

    do {
        swapped = 0;
        ptr1 = list->first;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void freeList(List *list){
    if(list->first == NULL){
        printf("\nThe list is already free!");
        return;
    }
    Node *actual = list->first;
    Node *next;

    while (actual->next != NULL){
        next = actual->next;
        free(actual);
        actual = next;
    }

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    printf("\nList completely free!");
}

int main() {
    int choice = 0, data, position;
    List list;

    startList(&list);

    while (choice != 12) {
        printf("\n");
        system("pause");
        //system("cls");

        printf("\nMenu");
        printf("\n1 - Print list");
        printf("\n2 - Search data");
        printf("\n3 - Add in the start");
        printf("\n4 - Add in the end");
        printf("\n5 - Add in defined position");
        printf("\n6 - Ordened insert");
        printf("\n7 - Remove first");
        printf("\n8 - Remove last");
        printf("\n9 - Remove in defined position");
        printf("\n10 - Remove determined data");
        printf("\n11 - Order list");
        printf("\n12 - Free list\n\n"); 
        scanf("%d", &choice);

        if (choice < 1 || choice > 12) {
            printf("\nInvalid option");
        } else {
            switch (choice) {
                case 1:
                    printList(list);
                    break;
                case 2:
                    printf("\nInsert the data you want to search: ");
                    scanf("%d", &data);
                    search(&list, data);
                    break;
                case 3:
                printf("\nInsert the data: ");
                scanf("%d", &data);
                    addFirst(&list, data);
                    break;
                case 4:
                    printf("\nInsert the data: ");
                    scanf("%d", &data);
                    addLast(&list, data);
                    break;
                case 5:
                    printf("\nInsert the data: ");
                    scanf("%d", &data);
                    addDeterminedPosition(&list, data);
                    break;
                case 6:
                    printf("\nInsert the data: ");
                    scanf("%d", &data);
                    ordenedInsert(&list, data);
                    break;
                case 7:
                    removeFirst(&list);
                    break;
                case 8:
                    removeLast(&list);
                    break;
                case 9:
                    removeDeterminedPosition(&list);
                    break;
                case 10:
                    printf("\nInsert the data you want to remove: ");
                    scanf("%d", &data);
                    removeDeterminedElement(&list, data);
                    break;
                case 11:
                    order(&list);
                    break;
                case 12:
                    freeList(&list);
                    break;
                default:
                    break;
            }
        }
    } 

    return 0;
}