int findRepeatNumber(int* nums, int numsSize){
    short *arr=(short*)malloc(sizeof(short)*numsSize);
    memset(arr,0,sizeof(short)*numsSize);
    int i;
    for(i=0;i<numsSize;i++){
        arr[nums[i]]++;
        if(arr[nums[i]]>1) break;
    }
    return nums[i];
}