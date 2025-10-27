/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* c=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    if(numsSize==0){
        c[0]=-1;
        c[1]=-1;
        return c;
    }
    int a=0,b=numsSize-1,mid=(a+b)/2,left=-1,right=-1;
    for(;a<b;){
        mid=(a+b)/2;
        if(nums[mid]>=target){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    
    if(target!=nums[b]){
        c[0]=-1;
        c[1]=-1;
        return c;
    }
    left=b;
    for(a=0,b=numsSize-1;a<b;){
        mid=(a+b)/2+(a+b)%2;
        if(nums[mid]>target){
            b=mid-1;
        }else{
            a=mid;
        }
    }
    right=a;
    c[0]=left;
    c[1]=right;
    return c;
}