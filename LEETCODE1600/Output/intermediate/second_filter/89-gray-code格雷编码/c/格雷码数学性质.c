/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int total=pow(2.0,n);
    int *a=malloc(sizeof(int)*total);
    *returnSize=total;
    for(int i=0;i<total;i++){
        a[i]=(i>>1)^i;
    }
    return a;
}