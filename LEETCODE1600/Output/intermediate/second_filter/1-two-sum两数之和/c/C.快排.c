/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void quick(int *nums,int *id,int begin,int end,int numsSize){
     if(begin>=end) return ;
     int flag=1;int pivot=nums[begin];int pivot1=id[begin];
     int i,j;
    for(i=begin,j=end;i<j;){
        if(flag){
          if(nums[j]>=pivot) j--;
          else {nums[i]=nums[j];id[i]=id[j];
          flag=0;i++;}
        }
        else{
          if(nums[i]<=pivot) i++;
          else {nums[j]=nums[i];id[j]=id[i];
          flag=1;j--;} 
        }
    }
    nums[i]=pivot;id[i]=pivot1;
    quick(nums,id,begin,i-1,numsSize);quick(nums,id,i+1,end,numsSize);
    
 }
 void quicksort(int *nums,int *id,int numsSize){
     quick(nums,id,0,numsSize-1,numsSize);
 }
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
      int *id=(int *)malloc(numsSize*sizeof(int));
      for(int i=0;i<numsSize;i++) id[i]=i;
      quicksort(nums,id,numsSize);
      int *s=(int *)malloc(2*sizeof(int));
      for(int i=numsSize-1,j=0;j<i;){
            if(nums[j]+nums[i]==target){
              s[0]=id[j];s[1]=id[i];
              *returnSize=2;
              return s;
            }
           else if(nums[j]+nums[i]>target) i--;
           else j++;
        
      }
       
       return NULL;
}