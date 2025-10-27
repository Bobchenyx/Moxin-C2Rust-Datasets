int minIncrementForUnique(int* A, int ASize){
    if(ASize==0)
    return NULL;
    if(ASize==1)
    return 0;
    int *nums=(int *)malloc(sizeof(int)*80000);
    memset(nums,0,sizeof(int)*80000);
    int count=0;
    for(int i=0;i<ASize;i++){
        nums[A[i]]++;
        if(nums[A[i]]>=2)
        count++;
    }
    if(count==0)
    return 0;
    int tick=0;int j=0;int diff=0;
    for(int i=0;i<80000;i++){
        if(nums[i]>1){
            tick=i;
            break;
        }
    }
    j=tick+1;
    while(count!=0&&j<80000){
        if(nums[j]==0){
            count--;
            diff+=j-tick;
            nums[tick]--;
            if(nums[tick]==1){
                while(nums[tick]<=1&&count!=0){
                    tick++;
                }
                if(tick>j)
                j=tick;
            }
        }
        j++;
    }
    return diff;
}