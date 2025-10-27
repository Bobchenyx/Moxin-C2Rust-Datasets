int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i=0,j=i+1,k=numsSize-1,ans=nums[i]+nums[j]+nums[k]-target,temp;
    qsort(nums, numsSize, sizeof(int), comp);//快速排序
    for(;i<numsSize-1;i++){
        j=i+1;k=numsSize-1;
        while(j<k){
            temp=nums[i]+nums[j]+nums[k]-target;
            ans=abs(ans)>abs(temp)?temp:ans;
            if(temp>0) k--;
            else if(temp<0) j++;
            else return ans+target;
        }
    }
    return ans+target;
}