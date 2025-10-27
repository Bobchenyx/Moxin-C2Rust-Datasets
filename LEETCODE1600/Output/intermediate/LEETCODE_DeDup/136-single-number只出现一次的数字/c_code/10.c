int singleNumber(int* nums, int numsSize){
    int max_num=nums[0];
    int min_num=nums[0];
    int result=0;
    for(int i=0;i<numsSize;i++){//找出最大值与最小值
        if(nums[i]>max_num){max_num=nums[i];}
        if(nums[i]<min_num){min_num=nums[i];}
    }
    int* pool=(int*)malloc((max_num-min_num+1)*sizeof(int));
    for(int i=0;i<max_num-min_num+1;i++){//置零操作
        pool[i]=0;
    }
    for(int i=0;i<numsSize;i++){//将所有负数转化为0
        nums[i]-=min_num;
    }
    for(int i=0;i<numsSize;i++){//找到某个数据后，对应位置加1
        pool[nums[i]]++;
    }
    for(int i=0;i<max_num-min_num+1;i++){
        if(pool[i]==1){//找到值为1的数据点
            result=i+min_num;//返回时需要减去min_num
            break;
        }
    }
    return result;
}