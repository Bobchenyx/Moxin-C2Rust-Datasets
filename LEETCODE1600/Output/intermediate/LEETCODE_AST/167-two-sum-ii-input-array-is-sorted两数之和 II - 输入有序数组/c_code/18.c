/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0;
    int right = numbersSize - 1;
    
    while(left < right){
        
        if(numbers[left] + numbers[right] == target){

            result[0] = left + 1;
            result[1] = right + 1;
            break;
        }
        else if(numbers[left] + numbers[right] > target){
                
            right--;
        }else{
                
            left++;
        }
    }
    
    return result;
}