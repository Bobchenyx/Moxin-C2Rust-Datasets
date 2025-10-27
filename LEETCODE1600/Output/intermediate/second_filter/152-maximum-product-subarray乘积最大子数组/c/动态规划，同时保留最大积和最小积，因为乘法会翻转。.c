#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
int maxProduct(int* nums, int numsSize){
    long long dpMax[numsSize];
    long long dpMin[numsSize];
    dpMax[0] = nums[0];
    dpMin[0] = nums[0];
    int pro = nums[0]; 

    for (int i = 1; i < numsSize; i++) {
        dpMax[i] = MAX(MAX(nums[i], dpMax[i - 1] * nums[i]), dpMin[i - 1] * nums[i]);        
        dpMin[i] = MIN(MIN(nums[i], dpMin[i - 1] * nums[i]), dpMax[i - 1] * nums[i]);        
        
        pro = MAX(dpMax[i], pro);
    }

    return pro;
}