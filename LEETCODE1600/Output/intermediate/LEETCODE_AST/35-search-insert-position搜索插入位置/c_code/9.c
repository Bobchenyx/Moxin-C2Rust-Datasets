int searchInsert(int* nums, int numsSize, int target){
    int l=0;
    int r=numsSize-1;
    int m = (l+r)/2;
    if(target < nums[l]) return 0;
    if(target > nums[r]) return numsSize;
    while(r-l>2)
    {
        if(nums[m] > target){
            r = m;
            m = (l+r)/2; 
        }
        else if(nums[m] < target){
            l = m;
            m = (l+r)/2;
        }
        else{
            return m;
        }
    }
    for(int i=l;i<=r;i++){
        if(nums[i] >= target){
            return i;
        }        
    }
    return 0;
}