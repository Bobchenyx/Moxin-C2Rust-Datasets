//#define MAX(a,b) ((a)>(b)?(a):(b))
//O(n)算法
int maxSubArray(int* nums, int numsSize){
    if(!numsSize) return 0;
    int i=0;//dp[numsSize+1];
    int max=nums[0];//max存最大和
    int pre = nums [0];//pre存 i-1 结尾的最大和
    for(i=1;i<numsSize;i++)
    {
        if(pre>=0)
            pre+=nums[i]; //若i-1结尾最大和为正，可以继续利用
        else
            pre = nums[i];  //若为负，则抛弃不用，新开一局
        //max=MAX(max,pre); 
        if(pre>max)
            max=pre;          
    }
    return max;
}