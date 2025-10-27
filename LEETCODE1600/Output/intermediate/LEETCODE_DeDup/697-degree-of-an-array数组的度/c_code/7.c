int findShortestSubArray(int* nums, int numsSize){
    if(numsSize == 0 || numsSize == 1)
    return numsSize;
    //分别标记一个数的度，及它出现的第一次和最后一次的位置
    int* degree = (int*)calloc(50000, sizeof(int));
    int* first = (int*)calloc(50000, sizeof(int));
    int* last = (int*)calloc(50000, sizeof(int));
    int i, temp, max=0, maxdegree = 0;
    for(i=0; i<numsSize; i++){
        temp = nums[i]; //储存数组当前的数
        degree[temp]++; //该数出现的度加一
        if(degree[temp] > maxdegree)
        maxdegree = degree[temp]; //记录数组的最大度

        if(degree[temp] == 1)//记录第一次出现的位置
        first[temp] = i;

        last[temp] = i; //记录最后一次的位置

        if(temp > max) //记录数组中出现过的最大数
        max = temp;

    }
    int minlen = INT_MAX;
    for(i=0; i<=max; i++){ //遍历度的数组时，查找到最大数就够了
        if(degree[i] == maxdegree){ //查找到最大度时，取最小长度
            temp = 1 + last[i] - first[i];
            minlen = minlen < temp ? minlen : temp;
        }
    }
    return minlen;
}