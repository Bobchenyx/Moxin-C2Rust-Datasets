int majorityElement(int* nums, int numsSize){
    //快速排序
    int low=0,high=numsSize-1,mid=0;
    while(mid!=numsSize/2) {
        mid=quickSort(nums,low,high);
        if(mid<numsSize/2) low=mid+1;
        else if(mid>numsSize/2) high=mid-1;
    }
    return nums[mid];
}

int quickSort(int* nums,int low,int high){//一次快速排序
    int base=nums[low];
    while(low<high) {
        while(low<high && base<nums[high]) high--;
        if(low<high) nums[low++]=nums[high];
        while(low<high && base>nums[low]) low++;
        if(low<high) nums[high--]=nums[low];
    }
    nums[low]=base;
    return low;
}