/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int min, max, mid, i, b;
    int *res = malloc(2 *sizeof(int));

    *returnSize = 2;
    for(i=0; numbers[i] <= target; i++){
        res[0] = i + 1;
        b = target - numbers[i];
        min = i + 1;
        max = numbersSize - 1;
        while (min <= max) {
            mid = (min + max)/2;
            //printf("mid=%d b=%d\n",mid, b);
            if(numbers[mid] == b) {
                res[1] = mid + 1;
                return res;
            } else if (numbers[mid] < b) {
                min = mid + 1;
            } else 
                max = mid - 1;
        }
    }
    return res;
}