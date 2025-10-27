int maxProduct(int* nums, int numsSize){
    int max = INT_MIN;
    int imax = 1;
    int imin = 1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < 0){
            imax = imax ^ imin;
            imin = imax ^ imin;
            imax = imax ^ imin;
        }
        imax = fmax(imax * nums[i], nums[i]);
        imin = fmin(imin * nums[i], nums[i]);
        max = fmax(max, imax);
    }
    return max;
}