/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *returnA=(bool *)malloc(sizeof(bool)*(ASize));
    *returnSize=ASize;
    int i;
    long long int num=0;
    for(i=0;i<ASize;i++){
        num=(num%10)*2+A[i];
        if(num%5==0)returnA[i]=true;
        else returnA[i]=false;
    }
    return returnA;
}