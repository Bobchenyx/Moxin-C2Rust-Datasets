/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h> 
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=*a;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *returnArr=(int*)malloc(k*sizeof(int));
    *returnSize=k;
    for(int i=0;i<k;i++){
        int min=arr[0],index=0;
        for(int j=0;j<arrSize-i;j++){
            if(min>arr[j]){
                min=arr[j];
                index=j;
            }
        }
        returnArr[i]=arr[index];
        swap(&arr[index],&arr[arrSize-i-1]);

    }

    return returnArr;
}