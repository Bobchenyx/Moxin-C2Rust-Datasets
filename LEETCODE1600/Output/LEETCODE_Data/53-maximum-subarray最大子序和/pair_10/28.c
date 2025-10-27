#define MAX(a,b) ((a)>(b)?(a):(b))
int maxSubArray(int* nums, int numsSize){
    
    int s=0,ms=nums[0],i;
    for(i=0;i<numsSize;i++){
        s += nums[i];
        ms = MAX(s,ms);
        s = MAX(s,0);        
    }
    return ms;
}