/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){

    int* nums=(int*)malloc(sizeof(int)*n);

    int low=0,high=n-1;
    int m=1;
    while(low<high)
    {
        nums[low++]=-1*m;
        nums[high--]=m;
        m++;
    }
    if(low==high)
        nums[low]=0;
    *returnSize=n;
    return nums;
}