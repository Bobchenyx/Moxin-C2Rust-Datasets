int majorityElement(int* nums, int numsSize){
    int first = nums[0];
    int cnt = 1;
    int second;
    for (int i = 1; i < numsSize; i++) {
        if (cnt == 0) {
            first = nums[i];
            cnt++;
            continue;
        }
        second = nums[i];
        if (second == first) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    return first;
}