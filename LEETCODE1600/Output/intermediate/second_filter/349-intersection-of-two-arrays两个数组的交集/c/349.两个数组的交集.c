/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
  int i,j,z,temp,num = 0;
  int maxNum = nums1Size<nums2Size?nums1Size:nums2Size;
  int *nums3 = (int*)malloc(sizeof(int)*maxNum);
  for(i=0;i<nums1Size;i++){
      temp = nums1[i];
      for(j=0;j<nums2Size;j++){
          if(temp==nums2[j]){
            if(num==0){
              nums3[num]=temp;
              num++;}
            else{
                for(z=0;z<num;z++){
                    if(temp==nums3[z]){
                      break;
                    }
                }
                if(z==num){
                  nums3[num]=temp;
                  num++;
                }
            }
          }
      }
  }
  *returnSize = num;
  return nums3;

}