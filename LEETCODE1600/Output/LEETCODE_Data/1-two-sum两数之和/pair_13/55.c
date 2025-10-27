/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0;i<numsSize;i++){
        int tmp;
        int* result_nums;
        tmp = target - nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(tmp == nums[j]){
                *returnSize = 2;
                result_nums = (int*)malloc(sizeof(int)* 2);
                result_nums[0] = i;
                result_nums[1] = j;
                return result_nums;
            }
        }
    }
       return 0;
}