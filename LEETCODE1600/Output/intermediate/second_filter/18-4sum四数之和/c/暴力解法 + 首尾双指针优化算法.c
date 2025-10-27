/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int** returnArray = (int **)malloc(sizeof(int *) * (numsSize * numsSize));
    *returnSize = 0;

    //排序
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (int i = 0; i < numsSize; i++) {
        if ((i > 0) && (nums[i] == nums[i - 1])) {
            continue;
        }
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[j] == nums[j - 1]) && (j > i + 1)) {
                continue;
            }

            int leftIndex, rightIndex, twoSum;
            leftIndex = j + 1;
            rightIndex = numsSize - 1;
            twoSum = nums[i] + nums[j];

            while (leftIndex < rightIndex) {
                if ((nums[leftIndex] + nums[rightIndex]) < (target - twoSum)
                    || ((leftIndex > j + 1) && (nums[leftIndex] == nums[leftIndex - 1]))) {
                    leftIndex++;
                } else if ((nums[leftIndex] + nums[rightIndex]) > (target - twoSum)
                    || ((rightIndex < numsSize - 1) && (nums[rightIndex] == nums[rightIndex + 1]))) {
                    rightIndex--;
                } else {
                    returnArray[*returnSize] = (int *)malloc(sizeof(int) * 4);
                    returnArray[*returnSize][0] = nums[i];
                    returnArray[*returnSize][1] = nums[j];
                    returnArray[*returnSize][2] = nums[leftIndex];
                    returnArray[*returnSize][3] = nums[rightIndex];
                    (*returnSize)++;
                    leftIndex++;
                    rightIndex--;
                }
            }
        }
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * (* returnSize));
    for (int index = 0; index < *returnSize; index++) {
        returnColumnSizes[0][index] = 4;
    }
    return returnArray;
}