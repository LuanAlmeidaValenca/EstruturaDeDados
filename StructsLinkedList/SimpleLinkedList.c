#include <stdio.h>
#include <stdlib.h>

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
        while (temp->next != NULL){
            printf("\nData %d: %d", i, temp->data);
            temp->next;
            i++;
        }
    }
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

void addDeterminedPosition(List *list, int data, int position){
    Node *new = malloc(sizeof(Node));
    if(!new){
        printf("\nMemory allocation error!");
        return;
    }
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
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else{
        Node *temp = list->first;
        while (temp->next->data < data || temp->next == NULL)
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
    printf("The first node was sucesfully removed");
}

void removeLast();
void removeDeterminedPosition();

void freeList(List *list){
    if(list->first == NULL){
        printf("The list is already free!");
        return;
    }
    Node *actual = list->first;
    Node *next;

    do{
        next = actual->next;
        free(actual);
        actual = next;
    }while (actual->next != NULL);

    list->first == NULL;
    list->last == NULL;
    list->size = 0;
}

int main() {
    int choice = 0, data;
    List list;

    while (choice != 10) {

        printf("\nMenu");
        printf("\n1 - Print list");
        printf("\n2 - Add in the start");
        printf("\n3 - Add in the end");
        printf("\n4 - Add in defined posicion");
        printf("\n5 - Ordened insert");
        printf("\n6 - Remove first");
        printf("\n7 - Remove last");
        printf("\n8 - Remove in defined position");
        printf("\n9 - Free list"); 
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid option");
        } else {
            switch (choice) {
                case 1:
                    printf("You chose 1: Beginning of the journey!\n");
                    break;
                case 2:
                    printf("You chose 2: Twice the start!\n");
                    break;
                case 3:
                    printf("You chose 3: Three is a magic number!\n");
                    break;
                case 4:
                    printf("You chose 4: Four sides of a square!\n");
                    break;
                case 5:
                    printf("You chose 5: Half a dozen!\n");
                    break;
                case 6:
                    printf("You chose 6: Perfect number!\n");
                    break;
                case 7:
                    printf("You chose 7: Lucky number!\n");
                    break;
                case 8:
                    printf("You chose 8: Infinity lying down!\n");
                    break;
                case 9:
                    printf("You chose 10: The maximum allowed number!\n");
                    break;
                default:
                    break;
            }
        }
    } 

    return 0;
}
