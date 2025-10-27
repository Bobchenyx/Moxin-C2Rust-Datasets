int removeElement(int* nums, int numsSize, int val) {
  if (numsSize == 0) {
      return 0;
  }
    //!  同26题 类似
    int slow = 0;
    for (int i = 0; i < numsSize; i++) {
       if (nums[i] == val) {
           
       } else {
          nums[slow] = nums[i];
           slow++;
       }
        
    }
    
    return slow;
    
    
}