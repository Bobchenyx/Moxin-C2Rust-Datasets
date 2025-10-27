/*
贪心策略：每次跳完之后距离终点最近
*/

#define PRINTF printf
int jump(int* nums, int numsSize){
    int step = 0;
    for(int i = 0; i < (numsSize - 1); ){ // 这里i用来控制跳跃步数
        int maxDest = numsSize - 1 - nums[i] - i;
        int next = i + nums[i];
        PRINTF("%d %d\n", i, step);
        if(next >= (numsSize - 1)){ // 下一步可以跳到结束
            step++;
            break;
        }
        for(int j = (i + 1); j <= (i + nums[i]); j++){
            int tempDest = numsSize - 1 - nums[j] - j;
            if(tempDest < maxDest){ // 找到离终点更近的位置
                maxDest = tempDest;
                next = j;
            }
        }
        i = next;
        step++;
    }
    return step;
}