/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (target < 0) {
        return NULL;
    }
    
    int **result = (int**)malloc(sizeof(int*) * target);
    *returnColumnSizes = (int*)malloc(sizeof(int) * target);
    if (result == NULL || *returnColumnSizes == NULL) {
        return NULL;
    }
    
    int left = 1;
    int sum = 0;
    for (int i = 1; i < target; i++) {
        sum += i;
        while(sum > target) {
            sum -= left;
            left++;
        }
        if (sum == target) {
            int length = i - left + 1;
            (*returnColumnSizes)[*returnSize] = length;
            result[*returnSize] = (int*)malloc(sizeof(int) * length);
            int index = 0;
            int count = left;
            while (count <= i) {
                result[*returnSize][index++] = count;
                count++;
            }
            (*returnSize)++;
        }
    }
    return result;
}