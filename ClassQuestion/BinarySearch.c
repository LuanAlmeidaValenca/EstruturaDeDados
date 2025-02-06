#include <stdio.h>

int BinarySearch(int *array, int element, int arraylenght){
    int start = 0, end = arraylenght - 1;

    while (start <= end){
        int mid = (start + end)/2;
        if(array[mid] == element){
            return mid;
        }else if (array[mid] < element){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

int testetamanho(int tamanho){
    for(int i = 0; i < tamanho; i++)
    printf("%d", i);
}

int main(){
    int *array;
    int lenght;

    printf("Insert the array lenght: ");
    scanf("%d", &lenght);

    array = malloc(lenght);

    testetamanho(lenght);

    return 0;
}