/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int num_arrays = 0; // 记录连续正数序列的个数
    int **arrays; // 保存正数序列
    int limit = (target - 1) / 2; // 因为序列至少两个数，如target=9，那么limit=4
    int sum = 0; // 保存一个连续正数序列的和
    int len; // 保存一个连续正数序列的长度

    for (int i = 1; i <= limit; ++i) {
        for (int j = i; ; ++j) {
            sum += j;
            if (sum > target) {
                sum = 0;
                break;
            }
            else if (sum == target) {
                
                if (num_arrays == 0) {
                    arrays = (int **)malloc((++num_arrays) * sizeof(int *));
                    *returnColumnSizes = (int *)malloc((num_arrays) * sizeof(int));
                }
                else {
                    arrays = (int **)realloc(arrays, (++num_arrays) * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, (num_arrays) * sizeof(int));
                }

                len = j - i + 1;
                
                (*returnColumnSizes)[num_arrays - 1] = len; 
                
                arrays[num_arrays - 1] = (int *)malloc(len * sizeof(int));
                for (int k = 0; k < len; ++k) {
                    arrays[num_arrays - 1][k] = i + k;
                }
                
                sum = 0;
                break;
            }
        }
    }
    *returnSize = num_arrays;
    return arrays;
}