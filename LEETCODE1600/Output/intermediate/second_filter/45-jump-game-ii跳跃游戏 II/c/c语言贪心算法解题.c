int jump(int* nums, int numsSize){
    if (numsSize < 2) {
        return 0;
    }
    int sum = 1 + nums[0], indexNum = 0, tempMax, tempIndex, res = 1;
    while (sum < numsSize) {
        tempMax = 0;
        for (int i = 0; i < nums[indexNum]; i++) {
            if (tempMax < 1 + i + nums[indexNum + i + 1]) {
                tempMax = 1 + i + nums[indexNum + i + 1];
                tempIndex = indexNum + i + 1;
            }
        }
        res++;
        sum = sum - nums[indexNum] + tempMax;
        indexNum = tempIndex;
    }
    return res;
}