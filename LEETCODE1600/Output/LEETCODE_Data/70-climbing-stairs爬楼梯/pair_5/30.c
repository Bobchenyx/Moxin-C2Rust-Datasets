int climbStairs(int n){
    if (n == 1)return 1;
	if (n == 2)return 2;
    int* nums=(int*)malloc(sizeof(int)*(n+1));
    nums[0]=0;nums[1]=1;nums[2]=2;
    for(int i=3;i<=n;++i)
        nums[i]=nums[i-1]+nums[i-2];
    int result= nums[n];
    free(nums);
    return result;
}