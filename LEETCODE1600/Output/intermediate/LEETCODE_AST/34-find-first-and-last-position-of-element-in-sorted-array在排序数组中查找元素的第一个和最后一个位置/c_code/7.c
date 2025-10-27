/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res = malloc(sizeof(int) * 2);
    res[0] = res[1] = -1;
    *returnSize = 2;
    if (numsSize == 0) {
        return res;
    }
    int lo = 0;
    int hi = numsSize - 1;
    int mid = (lo + hi) / 2;
    while (lo <= hi) {
        if (mid == lo && nums[mid] == target) {
            res[0] = mid;
            break;
        }
        if (nums[mid] == target && nums[mid - 1] < target) {
            res[0] = mid;
            break;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        mid = (lo + hi) / 2;
    }
    lo = 0;
    hi = numsSize - 1;
    mid = (lo + hi) / 2;
    while (lo <= hi) {
        if (mid == hi) {
            if (nums[mid] == target) {
                res[1] = mid;
            } 
            break;
        }
        if (nums[mid] == target && nums[mid + 1] > target) {
            res[1] = mid;
            break;
        } else if (nums[mid + 1] <= target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        mid = (lo + hi) / 2;
    }
    return res;
}