#define min(a,b) ((a)<(b)?(a):(b))
int minSubArrayLen(int s, int* nums, int numsSize){
    int L = 0, R = 0, sum = 0, res = 0x7fffffff;
    while (R < numsSize) {
        while (sum < s && R < numsSize) // 扩大窗口直到符合条件
            sum += nums[R++];
        while (sum >=s && L <= R) {     // 若符合条件先记录返回值，然后缩小窗口直到不符合条件
            res = min(res, R - L);
            sum -= nums[L++];
        }
    }   
    return res == 0x7fffffff ? 0 : res; // 若 res 仍为 “无穷大”，表示未找到
}