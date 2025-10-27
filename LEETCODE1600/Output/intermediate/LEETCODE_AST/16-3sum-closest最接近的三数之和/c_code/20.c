int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), comp);
    int sum=0,res=0;
    int dis=0,mindis=256;
    int oldi=0;int p=0,q=0;
    for(int i=0;i<numsSize-1;i++){
        if(oldi!=0&&nums[oldi]==nums[i]){
			continue;
		}
        p=i+1;q=numsSize-1;
        while(q-p>0){
            sum=nums[i]+nums[p]+nums[q];
            dis=abs(sum-target);
            if(dis==0){
                res=sum;
                break;
            }else{
                if(mindis>dis)mindis=dis,res=sum;
            }
            if(sum>target){
                q--;
            }
            if(sum<target){
                p++;
            }
        }
		if(dis==0){
           res=sum;
           break;
        }
    }
    return res;
}