int* sort(int* nums,int numsSize){  // 用的冒泡排序，还有更快的
    int temp;
    for(int i=1;i<numsSize;i++){
        for(int j=0;j<numsSize-i;j++){
            if(nums[j]>nums[j+1]){
            temp = nums[j];
            nums[j] = nums[j+1];
            nums[j+1] = temp;
            }
        }
    }
    return nums;
}

int abs(int a){
    if(a<0)return -1 * a;
    else return a;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int result, left, right;
    int temp;
    int n = numsSize;
    if(n < 3)return -1;
    result = nums[0]+nums[1]+nums[2];   // 给result赋初值
    nums = sort(nums, n);
    for(int i = 0;i <= n - 3;i++){
        left = i + 1;
        right = n - 1;
        while(left < right){
            temp = nums[i] + nums[left] + nums[right];
            if(abs(temp-target) < abs(result-target))result = temp;
            if(temp == target)return target;
            else if(temp < target){
                left++;
                continue;
            }
            else{
                right--;
                continue;
            }
        }
    }
    return result;
}