#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MMIN(a, b)      ((a) < (b)? (a) : (b))

int *memo;

int helper(int *nums, int numsSize, int sum, int mask) {
    if(memo[mask] > 0) {
        return memo[mask] - 1;
    }

    //找到第一个数字
    int sid = -1;
    for(int i = 0; i < numsSize; i++) {
        int id = 1 << i;

        if((mask & id) == 0) {
            sid = i;
            break;
        }
    }
    
    //找到最后一个数字
    int eid = -1;
    for(int i = numsSize - 1; i >= 0; i--) {
        int id = 1 << i;

        if((mask & id) == 0) {
            eid = i;
            break;
        }
    }

    if(sid == eid) {
        memo[mask] = sum + 1;
        return sum;
    }

    //当前玩家从下一个玩家可以获得的最低得分中，判断自己可以获得的最高得分。
    int ret = sum - MMIN(helper(nums, numsSize, sum - nums[sid], mask | (1 << sid)), helper(nums, numsSize, sum - nums[eid], mask | (1 << eid)));

    memo[mask] = ret + 1;
    return ret;
}

//【算法思路】DFS+记忆化+位运算。典型的游戏输赢类问题。
// memo[mask]用于记录pattern为mask时，在剩余的数据中，当前玩家可以获得的最大积分。
// 注意，当mask一定时，当前玩家获得的最大积分唯一。
bool PredictTheWinner(int* nums, int numsSize){
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    memo = (int *)calloc(pow(2, numsSize), sizeof(int));

    int ret = helper(nums, numsSize, sum, 0);

    return ret >= (sum - ret);
}