/**暴力法求解
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target,int *returnSize){
        int i,j;
        int *p=(int *)malloc(sizeof(int)*2);//需要动态分配内存
		  for(i=0;i<numsSize-1;i++)
		  {
		  	int temp=target-nums[i];
		  	for(j=i+1;j<numsSize;j++)
		  	{
		  		if(temp==nums[j])
		  		{
		  		  p[0]=i;
		  		  p[1]=j;
                  *returnSize=2;//返回数组大小
		  		  return p;
		  		}
		  	}
		  	
		  }      
        *returnSize=0;
		return p;  
              
}