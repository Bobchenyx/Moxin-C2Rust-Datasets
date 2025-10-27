/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a ,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr , int start , int end ){
    int privot = arr[start];
    while(start < end){
        while(start < end && arr[end] >= privot){
            end--;
        }
        if(start < end){
            arr[start++] = arr[end];
        }
        while(start < end && arr[start] <= privot){
            start++;
        }
        if(start < end){
            arr[end--] =  arr[start];
        }
    }
    arr[start] = privot;
    return start;
}


int* quickSort(int* arr , int start , int end , int k){
    if(start < end){
        int mid = partition(arr, start , end);
        if(mid == k ){
            return arr;
        }
        if(mid > k ){
            return quickSort(arr, start , mid , k);
        }
        if(mid < k ){
            return quickSort(arr, mid + 1 , end, k);
        }
    }
    return arr;
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(arr == NULL || arrSize < 0){
        *returnSize = 0;
        return NULL;
    }
    if(arrSize == 0 || k == 0 || arrSize < k){
        *returnSize = 0;
        return arr;
    }
    *returnSize = k;
    return quickSort(arr, 0 , arrSize -1 , k );
}