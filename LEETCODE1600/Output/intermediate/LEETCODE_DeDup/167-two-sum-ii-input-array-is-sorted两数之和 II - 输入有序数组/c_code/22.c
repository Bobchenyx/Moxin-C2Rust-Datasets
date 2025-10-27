int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int low = 0, high = numbersSize - 1;
    
    while (low < high){
        int cmp = numbers[low] + numbers[high];
        if (cmp > target)
            high -= 1;
        else if (cmp < target)
            low += 1;
        else{
            break;
        }
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = low + 1;
    res[1] = high + 1;
    return res;
}