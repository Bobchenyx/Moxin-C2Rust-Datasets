#define MAX_SIZE 10000
int Min(int a, int b)
{
    return a > b ? b : a;
}
int jump(int* nums, int numsSize){
    
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    
    for (int i = 1; i < numsSize; i++) {
        dp[i] = i;
        for (int j = 0; j <= i; j++) {
            if (j + nums[j] >= i) {
                dp[i] = Min(dp[i], dp[j]);
                break; // ???
            }
        }
        dp[i] += 1;
    }
    
    return dp[numsSize - 1];
    
}