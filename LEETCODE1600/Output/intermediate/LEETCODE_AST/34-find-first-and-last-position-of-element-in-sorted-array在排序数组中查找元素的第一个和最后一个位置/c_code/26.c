//先判读有没有这个数字
int binary_search(int *nums, int n, int target) {
    int l = 0, r = n - 1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
//查找第一个大于等于它的数
int binary_search1(int *nums, int n, int target) {
    int l = 0, r = n, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l == n ? -1 : l;
}
//查找第一个大于等于它的数
int binary_search2(int *nums, int n, int target) {
    int l = -1, r = n - 1, mid;
    while(l < r) {
        mid = (l + r + 1) >> 1;
        if(nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 3);
    int t, t1, t2 = 0;
    t = binary_search(nums, numsSize, target);
    if(t == -1) {
        arr[0] = arr[1] = -1;
        *returnSize = 2;
        return arr;
    }
    t1 = binary_search1(nums, numsSize, target);
    t2 = binary_search2(nums, numsSize, target);
    arr[0] = t1;
    arr[1] = t2;
    *returnSize = 2;
    return arr;
}