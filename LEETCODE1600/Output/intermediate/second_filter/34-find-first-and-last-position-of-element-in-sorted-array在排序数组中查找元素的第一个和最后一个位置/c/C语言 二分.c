int START(int *nums,int start,int end,int target){
    if(start>end||start<0||end<0){
        return -1;
    }
    
    if(nums[start]>target){
        return -1;
    }


    int mid=(start+end)/2;
    if(target>nums[mid]){
        if(mid+1>end)return -1;
        return START(nums,mid+1,end,target);
    }
    else if(target<nums[mid]){
        if(start>mid-1)return -1;
        return START(nums,start,mid-1,target);
    }
    else{
        if(target == nums[mid]){
            int t=0;
            if(start>(mid-1))
            {
                t=-1;
            }
            else{
               t= START(nums,start,mid-1,target);
            }
            if(t!=-1){
                return t;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}


int END(int *nums,int start,int end,int target){
    if(nums[start]>target){
        return -1;
    }
    if(start>end){
        return -1;
    }

    int mid=(start+end)/2;
    if(target>nums[mid]){
        if(mid+1>end)return -1;
        return END(nums,mid+1,end,target);
    }
    else if(target<nums[mid]){
        if(start>mid-1)return -1;
        return END(nums,start,mid-1,target);
    }
    else{
        if(target == nums[mid]){
            int t=0;
            if(mid+1>end)
            {
                t=-1;
            }
            else{
                t=END(nums,mid+1,end,target);
            }

            if(t!=-1){
                return t;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *line =(int*)malloc(sizeof(int)*2);
    if(numsSize==0){
        line[0]=-1;
        line[1]=-1;
        *returnSize=2;
        return line;
    }
    
    
    line[0]=START(nums,0,numsSize-1,target);
    line[1]=END(nums,0,numsSize-1,target);
    *returnSize=2;
    return line;
}