int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (mid + 1 < numsSize && nums[mid] < target) {
            left = mid + 1;
        }

        if (mid + 1 == numsSize && nums[mid] < target) {
            return numsSize;
        }

        if (mid >= 1 && nums[mid] > target) {
            right = mid - 1;
        }

        if (mid == 0 && nums[mid] > target) {
            return 0;
        }
    }

    if (nums[left] < target) {
        return left + 1;
    }
    return left;
}