int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int i,j,max=0,a[numsSize];
    a[numsSize-1]=1;
    for(i=numsSize-2;i>=0;i--){
        a[i]=1;
        for(j=i+1;j<numsSize;j++){
            if(nums[j]>nums[i])
                if(a[j]+1>a[i]) 
                    a[i]=a[j]+1;
        } 
    }
    max=a[0];
    for(i=0;i<numsSize;i++) printf("%d ",a[i]);
    for(i=1;i<numsSize;i++)
        if(a[i]>max) max=a[i];
    return max;
}