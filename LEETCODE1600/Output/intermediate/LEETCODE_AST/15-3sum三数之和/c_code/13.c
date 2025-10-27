int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), Compare);
    int now = 0;
    int low;
    int high;
    *returnSize = 0;
    long maxSize = (long)numsSize * 6;
    int **res = (int **)malloc(sizeof(int *) * maxSize);
    
    while (nums[now] <= 0 && (now + 2) < numsSize) {
        while (now > 0 && (now + 2) < numsSize&& nums[now] == nums[now - 1]) {
            now++;
        }
        if ((now + 2) >= numsSize) {
            break;
        }
        low = now + 1;
        high = numsSize - 1;
        int target = -nums[now];
        while(low < high) {
            if (nums[low] + nums[high] == target) {
                res[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                res[(*returnSize)][0] = nums[now];
                res[(*returnSize)][1] = nums[low];
                res[(*returnSize)][2] = nums[high];
                (*returnSize)++;
                int temp_low = nums[low];
                int temp_high = nums[high];
                while (low < numsSize && nums[low] == temp_low) {
                    low++;
                }
                while (high > now && nums[high] == temp_high) {
                    high--;
                }
                if (high <= low) {
                    break;
                }else {
                    continue;
                }
            } 
            
            if (nums[low] + nums[high] < target) {
                low++;
                continue;
            }
            
            if (nums[low] + nums[high] > target) {
                high--;
                continue;
            }
        }
        
        now++;
        low = now + 1;
        high = numsSize - 1;
        continue;

    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * 6 * numsSize);
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }
    
    return res;
}