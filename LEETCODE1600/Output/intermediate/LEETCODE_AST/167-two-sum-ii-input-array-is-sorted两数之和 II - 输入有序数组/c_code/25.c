/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int index1 = 0;
    int index2 = numbersSize - 1;

    while (numbers[index1] + numbers[index2] != target) {
        if (numbers[index1] + numbers[index2] > target) {
            index2--;
            continue;
        }
        if (numbers[index1] + numbers[index2] < target) {
            index1++;
        }
    }

    int *res = calloc(2, sizeof(int));
    res[0] = index1 + 1;
    res[1] = index2 + 1;
    *returnSize = 2;

    return res;
}