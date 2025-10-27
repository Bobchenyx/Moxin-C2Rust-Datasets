int removeDuplicates(int* nums, int numsSize){
    int i,j;    //i用于存储第一个不相同的元素，j为工作指针
    if(numsSize==0)
    return 0;
    for(i=0,j=1;j<numsSize;j++){
        if(nums[i]!=nums[j]){   //查找下一个与上一个元素值不同的元素
            nums[++i]=nums[j];  //找到后，将元素前移
        }
    }
    return i+1;
}