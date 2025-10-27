int singleNumber(int* nums, int numsSize){
    int a=0,i=0;
    while(i<numsSize){
        a=a^nums[i];
        i++;
    }
    return a;
}