/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* data_buf=(int*)malloc(sizeof(int)*(numsSize+1));
    memset(data_buf,'\0',sizeof(int)*(numsSize+1));

    for(int i=0;i<numsSize;i++){
        for(int j=0;j<numsSize;j++){
            if(nums[j]<nums[i])
                data_buf[i]++;
        }
    }

    data_buf[numsSize]='\0';
    *returnSize=numsSize;

    return data_buf;
}