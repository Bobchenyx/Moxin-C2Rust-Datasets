#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

//【算法思路】贪心算法。每一次折线，方向相同时，刷新新值，这样更容易获得新的折线。
int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2) {
        return numsSize;
    } else if(numsSize == 2) {
        return nums[1] == nums[0]? 1 : 2;
    }

    int *ret = (int *)calloc(numsSize, sizeof(int));
    int rsize = 0;

    ret[rsize++] = nums[0];
    int is_up = -1;

    for(int i = 1; i < numsSize; i++) {
        //如果和顶部元素相同，则继续
        if(nums[i] == ret[rsize - 1]) {
            continue;
        }

        if(is_up == -1) {
            //初次处理，对is_up标志赋值
            is_up = nums[i] > ret[rsize - 1]? 1 : 0;
            ret[rsize++] = nums[i];
        } else if(is_up == 0) {
            //之前为下降
            if(nums[i] > ret[rsize - 1]) {
                is_up = 1;
                ret[rsize++] = nums[i];
            } else {
                ret[rsize - 1] = nums[i];
            }
        } else if(is_up == 1) {
            //之前为上升
            if(nums[i] > ret[rsize - 1]) {
                ret[rsize - 1] = nums[i];
            } else {
                is_up = 0;
                ret[rsize++] = nums[i];
            }
        }
    }

    return rsize;
}