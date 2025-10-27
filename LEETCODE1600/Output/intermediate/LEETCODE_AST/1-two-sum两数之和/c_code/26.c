/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i ,z ,j;
    z = target ;
    int *a = nums ;
    int  *b ;
    b = (int *)malloc(sizeof(int)*2);
    for(i=0 ; i<numsSize ; i++)
    {
        for( j=i+1 ; j<numsSize ;j++)
        {
            if((*(a+i) + *(a+j)) == z)
            {
                *b = i ;
                *(b+1) = j ;
                *returnSize = 2 ;
                return b ;
            }
        }
    }
    *returnSize = 0 ;
    return b ;

}