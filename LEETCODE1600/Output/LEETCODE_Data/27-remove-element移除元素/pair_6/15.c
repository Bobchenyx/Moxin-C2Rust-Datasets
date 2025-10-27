int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0) return 0;
    int last = numsSize;
    int i=0;
    while(i<last)
    {
        if(nums[i]==val&&i<last-1)   //将i位置顶替 i后还有元素
        {
            turnOne(nums,i,last-1);
            last--;
        }
        if(nums[i]==val&&i==last-1)  // i位置需要舍弃 且i是最后一个需要判断的元素，直接缩短1 
        {
            last--;
            break;

        }
        if(nums[i]!=val) //非相同元素 指针向后移动。 不可用else，逻辑上与上一个if搭配，执行会出错。
        {
            i++;
        }
    }
    return last;
}

void turnOne(int *nums,int first,int last) 
//用于顶替掉位置为nums[first]的元素，末尾元素为numa[last]。
{
    while (first<last)
    {
        nums[first] = nums[first+1];
        first++;
    }
}