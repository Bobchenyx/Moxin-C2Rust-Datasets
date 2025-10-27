/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    int *returnValues = (int *) malloc(sizeof(int) * 2);
    if (returnValues == NULL)
    {
        return 0;
    }
    
    *returnSize = 2;
    
    int i, j;

    
    for (i = 0, j = numbersSize - 1; i < numbersSize; i ++)
    {
        while(j - 1 > i && numbers[i] + numbers[j - 1] >= target)
        {
            j --;
        }
        if (numbers[i] + numbers[j] == target)
        {
            returnValues[0] = i + 1;
            returnValues[1] = j + 1;
            return returnValues;
        }
    }

    return 0;
}