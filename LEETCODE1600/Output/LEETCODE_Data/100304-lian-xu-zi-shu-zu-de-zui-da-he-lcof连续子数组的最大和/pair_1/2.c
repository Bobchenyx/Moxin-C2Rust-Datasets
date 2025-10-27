#define max(a,b) a+b<a?a:a+b

int maxSubArray(int* nums, int numsSize){
    int result;
    int tool;
    result=tool=nums[0];
    for(int i=1;i<numsSize;i++){
        tool=max(nums[i],tool);
        result=tool<result?result:tool;
    }
    return result;
}