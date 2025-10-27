int removeDuplicates(int* nums, int numsSize){
    int temp=nums[0],count=1;                   //nums[0]为新数组第一个元素，temp用于判断是否重复
    if(numsSize==0) return 0;
    for(int i=1;i<numsSize;i++){
        if(temp!=nums[i]){
            temp=nums[count++]=nums[i];         //不同则将当前nums[i]接在“新”数组后面并赋值给temp
        }
    }
    return count;
}