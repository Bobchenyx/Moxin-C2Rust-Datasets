void reverse(int *nums,int left, int right){
    while(left<right){
        int tmp = nums[left];
        nums[left]= nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(k&&k<numsSize){
        int left = 0;
        int right = numsSize-k;
        int lenght = numsSize;
        reverse(nums,left,right-1);
        reverse(nums,right,numsSize-1);
        reverse(nums,left,numsSize-1);
    }else if(k>numsSize){
        int step = k%numsSize;
        rotate(nums,numsSize,step);
    }
}