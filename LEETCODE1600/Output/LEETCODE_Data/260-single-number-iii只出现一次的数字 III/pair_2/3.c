/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int temp1=0,temp2=0,count=0;
    for(int i=0;i<numsSize;i++){
        temp1 = temp1^nums[i]; 
    }
    temp2 = temp1;
    while((temp2&1)==0){
        count++;
        temp2 = temp2>>1;
    }
    temp2 = 0;
    for(int i=0;i<numsSize;i++){
        if((nums[i]>>count)&1 == 1){
            temp2 = temp2^nums[i];
        }
    }
    result[0] = temp2;
    result[1] = temp1^temp2;
    return result;
}