/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numbersSize, int target, int* returnSize){

    int *res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0;
    int j = numbersSize - 1;
    while(true){
        if (nums[i] + nums[j] > target) {
            j--;
        } else if (nums[i] + nums[j] < target) {
            i++;
        } else{
            res[0] = i+1;
            res[1] = j+1;
            break;
        }
    }
    return res;

}