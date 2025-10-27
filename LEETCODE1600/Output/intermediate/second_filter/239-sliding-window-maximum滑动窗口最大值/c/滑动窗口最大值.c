/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(nums==NULL||numsSize==0||k<=0||numsSize<k){
        *returnSize=0;
        return NULL;
    }
    *returnSize=numsSize-k+1; 
    int start=0,end;
    int *ans=(int*)malloc(sizeof(int)*(numsSize-k+1));
    int j=0,i=0;
    //limits.h头文件中的INT_MIN
    int max;
    int maxIndex=-1;
    for(start=0,end=k-1;end<numsSize;end++,start++){
        printf("start=%d,end=%d\t",start,end);
        //判断maxIndex是否在滑动窗口内
        if(maxIndex>=start&&maxIndex<=end){
            //如果在滑动窗口内则只需判断nums[end]是否大于nums[maxIndex]
            if(nums[end]>=nums[maxIndex]){
                maxIndex=end;
            }
        }else{
            maxIndex=start;
            //否则就原始地遍历这个窗口找到最大值
            for(i=start+1;i<=end;i++){
                if(nums[i]>=nums[maxIndex]){
                    maxIndex=i;
                } 
            }
        }
        ans[j]=nums[maxIndex];
        j++;
    }

    return ans;
}