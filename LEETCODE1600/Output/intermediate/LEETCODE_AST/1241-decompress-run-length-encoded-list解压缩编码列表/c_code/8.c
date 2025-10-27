/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int resultLength = 0;
    int i = 0,j=0,resultIndex=0;
    while(i<numsSize){
        resultLength+=nums[i];
        i+=2;
    }
    int* result = (int*)calloc(resultLength,sizeof(int));
    for(i=0;i<numsSize-1;i+=2){
        j=0;
        while(j<nums[i]){
            result[resultIndex+j] = nums[i+1];
            j++;
        }
        resultIndex+=nums[i];
    }
    *returnSize = resultLength;
    return result;
}