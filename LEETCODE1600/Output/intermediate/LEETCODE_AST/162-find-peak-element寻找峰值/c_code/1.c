#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

//【算法思路】二分查找。
// 本题关键点在于题目条件：1.num[i] != num[i + 1]；2.num[-1] == num[n] == INT_MIN
// 因此根据mid点位置的变化趋势，即可以选择二分移动方向
// 这里注意二分模板，mid = (ll + rr) / 2;ll = mid + 1;rr = mid。隐含着搜索位置的移动
int findPeakElement(int* nums, int numsSize){
    if(numsSize == 1) {
        return 0;
    }

    int ll = 0, rr = numsSize - 1;

    while(ll < rr) {
        int mid = (ll + rr) / 2;

        if(nums[mid] < nums[mid + 1]) {
            ll = mid + 1;
        } else {
            rr = mid;
        }
    }

    return ll;
}