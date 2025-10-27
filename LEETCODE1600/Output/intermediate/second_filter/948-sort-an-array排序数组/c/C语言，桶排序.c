/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int t[100001]={0};                              //建立空桶
    for(int i=0;i<numsSize;i++){
        ++t[nums[i]+50000];                         //向桶里加旗子
    }
    int* ans=(int*)malloc(sizeof(int)*numsSize);
    int j =0;
    for(int i=0;i<100001;i++){
        while(t[i]>0){
            ans[j++] = i-50000;
            --t[i];                                 // 当桶子里有旗子时拔出，直到没有旗子为止
        }
    }
    return ans;
}