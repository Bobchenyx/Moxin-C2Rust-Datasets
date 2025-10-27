int majorityElement(int* nums, int numsSize){
      int cndidate=nums[0],count=1;
      for(int i=1;i<numsSize;i++){
          if(count==0){
              cndidate=nums[i];
              count++;
          }
          else{
              if(cndidate==nums[i]) count++;
              else count--;
          }
    
      }
      return cndidate;
}