int removeDuplicates(int* nums, int numsSize){
    if( numsSize <= 1 )
        return numsSize;

    int cur = nums[0], i = 0, count = 0;

    for( i = 0; i < numsSize; i ++ )//用i检索，cur记录，count赋值
    {
        if( nums[i] != cur )
        {
            count++;
            nums[count] = nums[i];
            cur = nums[i];
        }
    }
    
    return count+1;//注意此处count从0开始计数做下标，需加1
}