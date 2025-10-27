/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i = 0, j = numbersSize - 1;
    int *results = (int *)malloc(sizeof(int) * 2);

    while(i < j)
    {
        if((numbers[i] + numbers[j]) < target)
        {
            i++;
        }
        else if((numbers[i] + numbers[j]) > target)
        {
            j--;
        }
        else
        {
            *returnSize = 2;
            results[0] = i + 1;
            results[1] = j + 1;
            return results;
        }
    }

    return results;
}