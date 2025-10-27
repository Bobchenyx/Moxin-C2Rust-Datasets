int jump(int* nums, int numsSize){
    if(numsSize<1)return 0;
    int step = 0;
    int minPos = 0;
    int minTmp = 0;
    int maxPos = 0;
    int maxTmp = 0;
    int minStep = 0;
    int maxStep = 0;

    while(maxPos<numsSize-1){
        minTmp = maxPos;
        maxTmp = minPos;
        for(int i=minPos;i<=maxPos;i++){
            minStep = nums[i] > 0 ? 1 : 0;
            maxStep = nums[i] > 0 ? nums[i] : 0;
            minTmp = i + minStep < minTmp ? i + minStep : minTmp;
            maxTmp = i + maxStep > maxTmp ? i + maxStep : maxTmp;
        }
        minPos = minTmp;
        maxPos = maxTmp;
        step++;
    }
    return step;
}