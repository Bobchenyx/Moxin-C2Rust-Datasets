int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //待返回数据初始化
    *returnSize=1;
    for(int i=0;i<numsSize;i++){
        (*returnSize)*=i+1;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    int** returnNums = (int**)malloc(sizeof(int*)*(*returnSize));
    
    //indexes 记录元素索引
    int* indexes = (int*)malloc(sizeof(int)*numsSize);
    //hashSet 记录元素使用情况，若是某个元素被占用，其对应的hash值为1，否则为0
    int* hashSet = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        indexes[i]=i;
        hashSet[i]=1;
    }
    

    //tail 尾指针(用于"进位"操作)
    int tail = numsSize-1;

    int count = 0;
    while(tail>=0){
        //记录排列
        (*returnColumnSizes)[count] = numsSize;
        returnNums[count] = (int*)malloc(sizeof(int)*numsSize);
        for(int i=0;i<numsSize;i++){
            returnNums[count][i]=nums[indexes[i]];
        }
        count++;
        

        int isReplace = false;
        int replaceByIndex = 0;
        while(tail>=0 && !isReplace){
            for(int i=indexes[tail]+1;i<numsSize;i++){
                //从闲置的元素中，查找替代项（即大于当前元素的最小闲置元素）
                if(!hashSet[i]){
                    isReplace = true;
                    replaceByIndex = i;
                    break;
                }
            }
             
            //把当前元素状态变为"闲置"
            hashSet[indexes[tail]]=0;
            
            if(isReplace){
                //如果找到合适的元素，就用该元素替代当前元素，并将替代元素状态置为"已占用"
                hashSet[replaceByIndex] = 1;
                indexes[tail] = replaceByIndex;
                //按照升序对剩下的闲置元素进行排列
                for(int i=0;i<numsSize;i++){
                    if(!hashSet[i]){
                        tail++;
                        indexes[tail]=i;    
                        hashSet[i]=1;
                    }
                }
            }else{
                //如果没找到合适的替代元素，就"进位"
                tail--;
            }
        }    
    
    }
    

    free(indexes);
    free(hashSet);
    return returnNums;
}