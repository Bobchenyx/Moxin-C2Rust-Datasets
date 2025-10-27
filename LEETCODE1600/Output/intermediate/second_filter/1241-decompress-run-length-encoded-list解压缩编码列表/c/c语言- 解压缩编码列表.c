/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
        int * returnA;
        returnA=(int *)malloc(sizeof(int)*(10000));
        int p=0,i=0,num,sum=0;
        while(i<numsSize-1){
            num=nums[i];//num为解压数字个数
            sum+=num;//sum求数组大小
            while(num!=0){//存储到数组里
                returnA[p++]=nums[i+1];
                num--;
            }//while
            i=i+2;
        }
        *returnSize=sum;
        return returnA;
}