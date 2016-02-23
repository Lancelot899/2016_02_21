/*************************************************************************
	> File Name: bubble_sort.c
	> Created Time: Sun 21 Feb 2016 05:26:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int size){
    if (NULL == array){
        printf("array is empty!\n");
        exit(0);
    }
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1 - i; ++j){
            if(array[j] > array[j + 1]){
                int tmp =  array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main(){
    int a[10] = {2,1,3,4,5,7,6,9,0,8};
    bubble_sort(a, 10);
    for(int i = 0; i < 10; ++i){
        printf("a[%d] = %d\t", i + 1, a[i]);
    }
    return 0;
}
