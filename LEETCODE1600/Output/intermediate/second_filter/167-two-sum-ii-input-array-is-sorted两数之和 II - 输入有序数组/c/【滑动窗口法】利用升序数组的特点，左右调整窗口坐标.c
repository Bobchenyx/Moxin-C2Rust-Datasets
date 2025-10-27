int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0;
	int right = numbersSize - 1;
    int *ret = NULL;
    ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    ret[0] = ret[1] = 0;

    while (left < right) {
            if(numbers[left] + numbers[right] == target) {
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            }
			else if(numbers[left] + numbers[right] > target) {
                right--;
            }
			else if(numbers[left] + numbers[right] < target) {
                left++;
            }

    }
    
    return ret;
}