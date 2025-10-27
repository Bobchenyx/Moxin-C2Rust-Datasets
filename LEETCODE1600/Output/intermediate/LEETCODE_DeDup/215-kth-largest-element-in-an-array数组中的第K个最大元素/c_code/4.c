int partition(int* nums,int low,int high,int k){
    int pivot = nums[low],i=low,j=high;
    while(low<high){
        while(low<high && nums[high]<=pivot) high--;
        nums[low] = nums[high];
        while(low<high && nums[low]>=pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    if(low == k-1){
        return nums[low];
    }else if(low < k-1){
        return partition(nums,low+1,j,k);
    }else{
        return partition(nums,i,low-1,k);
    }
}
int findKthLargest(int* nums, int numsSize, int k){
    return partition(nums,0,numsSize-1,k);
}