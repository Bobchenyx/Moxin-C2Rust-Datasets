/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
   int *nums=(int*)malloc(sizeof(int)*(digitsSize+1));
   for(int i=digitsSize-1;i>=0;i--){
       if(digits[i]<9){
           digits[i]++;
           *returnSize=digitsSize;
           return digits;
       }
        digits[i]=0;
       
   }
   *returnSize=digitsSize+1;
   for(i=1;i<digitsSize+1;i++)
    nums[i]=0;
    nums[0]=1;
    return nums;
  
}