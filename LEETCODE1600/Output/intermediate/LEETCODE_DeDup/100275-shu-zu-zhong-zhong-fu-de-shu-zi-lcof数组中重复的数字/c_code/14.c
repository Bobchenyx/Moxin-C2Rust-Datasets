int findRepeatNumber(int* nums, int numsSize){

    int pot[100005]={0};//开辟数组，记录位置
    for(int i=0;i<numsSize;i++)//依次循环
    {
        if(pot[nums[i]]==0)//判断是否是第一次出现
        pot[nums[i]]=1;//在pot数组中标记该数字出现过
        else return nums[i];//若不是第一次出现，则返回该数字
    }

    return 0;

}


int findRepeatNumber(int* nums, int numsSize){//抽屉原理 待补充完全
    int temp=0;
    for(int i=0;i<numsSize;i++)
    {
        while (nums[i]!=i)
        {
        if (nums[i]==nums[nums[i]])
        return nums[i];
        else {
        temp=nums[nums[i]];
        nums[nums[i]]=nums[i];
        nums[i]=temp;
        }
        }
    }
    return 0;
}