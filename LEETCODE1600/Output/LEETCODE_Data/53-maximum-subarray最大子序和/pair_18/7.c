#define max(a,b)  (a>b ? a:b)
int maxSubArray(int* nums, int numsSize){
    int i = 0;
    int sum = 0;
    int max_left = 0,max_right = 0;
    int max_midleft = 0,max_midright = 0,max_mid =0;
    //1,结束条件
    if ((numsSize==0) || (numsSize==1)) return nums[0];  
    //2,递归求左右最大
    max_left = maxSubArray(&nums[0], numsSize / 2);
    max_right = maxSubArray(&nums[numsSize / 2], numsSize-numsSize / 2);
    //3,求横跨中间最大 以中间为起点 先左向最大后右向最大 最后左右求和减中间重复元素
    max_midleft = nums[numsSize / 2];
    for (i = numsSize / 2; i >= 0; i--){
        sum += nums[i];
        if (sum > max_midleft){
            max_midleft = sum;
        }
    }
    sum=0;
    max_midright = nums[numsSize / 2];
    for (i = numsSize / 2 ; i < numsSize; i++){
        sum += nums[i];
        if (sum > max_midright){
            max_midright = sum;
        }
    }
    max_mid=max_midleft + max_midright - nums[numsSize / 2];
    //4,三者比较返回最大值
    return max(max(max_left,max_right),max_mid);
}