/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int*target = (int*)malloc(numsSize*sizeof(int));
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=numsSize-1;j>index[i];j--){
            target[j]=target[j-1];
        }
        target[j]=nums[i];
    }
    *returnSize=numsSize;
    return target;
}