// 递归算法超时
// int massage(int* nums, int numsSize){
//     if(numsSize == 1)
//         return nums[0];
//     else if(numsSize <= 0)
//         return 0;
//     else {
//         int r1 = nums[0] + massage(&nums[2], numsSize - 2);
//         int r2 = nums[1] + massage(&nums[3], numsSize - 3);
//         return r1 > r2 ? r1 : r2;
//     }
//     return -1;
// }

// 动态规划
int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int r1 = 0;
    int r2 = nums[0];
    for(int i = 1; i <numsSize; i++) {
        int temp = r1;
        r1 = r1 > r2 ? r1 : r2;
        r2 = temp + nums[i];
    }
    return r1 > r2 ? r1 : r2;
}