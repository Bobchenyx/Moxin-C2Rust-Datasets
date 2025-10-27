/*
first, count every rows' 1s, and stores them in a colsize array
then using a int small to select these k cols for return.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    *returnSize = 0;
    int i,j,small=0,num=0;
    int* arr = (int *)malloc(sizeof(int)*(matSize));
    //printf("matSize=%d, *matColSize =%d\n",matSize, *matColSize);
    
    for(i=0;i<matSize;i++)//initialize the array
        arr[i]=0;
    
    for(i=0;i<matSize;i++){
        for(j=0;j<*matColSize && mat[i][j]==1;j++)
            arr[i]++;
    }//calculate the solder num
    
    int* res = (int *)malloc(sizeof(int)*k);
    while(num!=k){//traverse all the small situations
        for(i=0;i<matSize;i++){
            if(arr[i]==small && num<k){
                res[num]=i;
                num++;
            }
        }
        small++;
    }
    
    *returnSize = k;
    return res;
}