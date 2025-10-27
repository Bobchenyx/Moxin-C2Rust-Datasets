int removeElement(int* nums, int numsSize, int val){
    int location , j , temp ;

    for(location=0;location<numsSize;)
    {
        //location是要考察的元素，如果location和val相等就
        //从location+1到numSize-1依次向前挪动一个位置
        //如果不相等的话就直接location++
        if(nums[location] == val)
        {
            for(j=location+1;j<numsSize;j++)
            {
                temp = nums[j] ; nums[j] = nums[j-1] ; nums[j-1] = temp;
            }

            numsSize--;
        }
        else
        {
            location++;
        }
    }

    return numsSize;
}