int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    //数组长度小于3，无解
    if(numsSize<3){
        return 0;
    }
    if(numsSize==3){
        return nums[0]+nums[1]+nums[2];
    }
    //数组排序
    qsort(nums,numsSize,sizeof(int),comp);
   
    //如果最小的三个数加起来都大于等于目标值，那么解肯定就是最小的三个值
    //同理，最大的三个值也是一样的
    if((nums[0]+nums[1]+nums[2])>=target){
        return nums[0]+nums[1]+nums[2];
    }
    else if((nums[numsSize-1]+nums[numsSize-2]+nums[numsSize-3])<=target){
        return (nums[numsSize-1]+nums[numsSize-2]+nums[numsSize-3]);
    }
    //其他情况就要用指针判断了
    else{
        //先遍历一遍，确定左指针的边界
        int i=0;
        while((nums[i]+nums[i+1]+nums[i+2])<=target){
            i++;
        }
        //上一步while循环恰巧有相等的，直接返回即可
        if((nums[i-1]+nums[i]+nums[i+1])==target){
            return target;
        }
        int left=i-1;
        int middle=left+1;
        int right=numsSize-1;
        //确定初始和和初始差距
        int result=nums[left]+nums[middle]+nums[right];
        int sum=nums[left]+nums[middle]+nums[right];
        int gap=((target>=sum)?(target-sum):(sum-target));
        
        //固定左边值，从i-1位置开始，遍历到0
        while(left>=0){
            middle=left+1;
            right=numsSize-1;
            while(middle<right){
                sum=nums[left]+nums[middle]+nums[right];
                if(sum<target){
                    if(target-sum<gap){
                        result=sum;
                        gap=target-sum;
                    }
                    middle++;
                }
                else if(sum>target){
                    if(sum-target<gap){
                        result=sum;
                        gap=sum-target;
                    }
                    right--;
                }
                else{
                    return sum;
                }
            }
            left--;
        }
        return result;
    }
}