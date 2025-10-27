int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j;
int *a;

    for(i = 0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if( ( nums[i] + nums[j] ) == target){
                if( i != j ){
                    a = (int *)malloc(sizeof(int) * 2);
                    *a   =  i;
                    a[1] =  j;
                    *returnSize = 2;
                    return a;
                } 
            }
        }
    } 
*returnSize = 0;
return a;
}