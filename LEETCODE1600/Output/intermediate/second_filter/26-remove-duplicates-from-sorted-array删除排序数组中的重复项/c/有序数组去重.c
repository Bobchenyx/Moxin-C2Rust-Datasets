int removeDuplicates(int* nums, int numsSize){
    if (numsSize < 0) return 0;
    if (numsSize <= 1) return numsSize;
    
    int current = 0;
    int slide = 1;
   
    while (slide < numsSize){
        if (nums[slide] != nums[current]) {
            nums[current+1] = nums[slide];
            current+=1;
        }
        slide++;
    }
    return current+1;

}