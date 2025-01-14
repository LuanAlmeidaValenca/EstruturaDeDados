#include <stdio.h>

int BinarySearch(int *array, int element, int listlenght){
    int start = 0, end = listlenght - 1;

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