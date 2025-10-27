int getValCnt(int* nums, int numsSize, int val)
{
    int i;
    int cnt = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            cnt++;
        }
    }
    return cnt;
}
void proc(int* nums, int numsSize, int val)
{
    int l, r;
    int tmp;
    l = 0;
    r = numsSize - 1;
    while (l < r) {
        if (nums[l] != val) {
            l++;
            continue;
        }
        if (nums[r] == val) {
            r--;
            continue;
        }
        tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
}
int removeElement(int* nums, int numsSize, int val){
    int rlt;
    int cnt;
    cnt = getValCnt(nums, numsSize, val);
    if (cnt == 0) {
        return numsSize;
    }
    proc(nums, numsSize, val);
    return numsSize - cnt;
}