int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    if(numbers && numbersSize != 0){
        int i = 0, j = numbersSize - 1;
        while(i < j){
            if(target == numbers[i] + numbers[j]){
                int *p = (int*)malloc(sizeof(int) * 2);
                *returnSize = 2;
                p[0] = i + 1;
                p[1] = j + 1;
                return p;
            }
            else if(target > numbers[i] + numbers[j]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}