int dominantIndex(int* nums, int numsSize){
    int Fst = -1;int Sec = -1;int index = 0;
    for (int i = 0;i < numsSize;i++)
    {
        if (nums[i] > Fst)
        {
            Sec = Fst;
            Fst = nums[i];
            index = i;
        }
        else if (nums[i] > Sec)
        {
            Sec = nums[i];
        }
    }
    return Fst>=Sec*2 ? index:-1;
}