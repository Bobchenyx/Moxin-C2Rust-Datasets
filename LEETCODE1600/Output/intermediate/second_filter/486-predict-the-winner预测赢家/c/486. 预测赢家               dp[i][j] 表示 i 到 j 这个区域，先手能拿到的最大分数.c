#define MAX(a,b) ((a)>(b)?(a):(b))
bool PredictTheWinner(int* nums, int numsSize){
     int i,j;
     int dp[1000][1000];

     memset(dp,0,100*100*sizeof(int));
     //dp = (int *)malloc(numsSize*numsSize*sizeof(int));

     dp[numsSize-1][numsSize-1] = nums[numsSize-1];
     for(i=numsSize-2;i>=0;i--){
         dp[i][i] = nums[i];
         for(j=i+1;j<numsSize;j++){
             dp[i][j] = MAX(nums[j]-dp[i][j-1], nums[i] - dp[i+1][j]);
         }
     }

     return dp[0][numsSize-1] >= 0;
}