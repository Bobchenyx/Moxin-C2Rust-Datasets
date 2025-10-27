#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int ret_[2];
int *ret = {ret_};

//【算法思路】二分查找。
// 1.按照二分法模板，退出的位置，为第一个大于tar的数据,因此可以找到数据的右边界。
// 2.将查找目标减一，退出的位置，即为查找目标的开始位置。
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    if(numsSize == 0 || target < nums[0] || target > nums[numsSize - 1]) {
        goto FAIL;
    }

    int ll = 0, rr = numsSize - 1;
    //先找到右边界
    if(nums[rr] == target) {
        ret[1] = rr;
    } else {
        while(ll < rr) {
            int mid = (ll + rr) / 2;

            if(nums[mid] > target) {
                rr = mid;
            } else {
                ll = mid + 1;
            }
        }

        if(nums[ll - 1] == target) {
            ret[1] = ll - 1;
        } else {
            goto FAIL;
        }
    }

    //再寻找左边界
    ll = 0, rr = numsSize - 1;
    if(nums[ll] == target) {
        ret[0] = ll;
    } else {
        //关键点：将target减小1，用同样代码找到右边界
        int tar = target - 1;

        while(ll < rr) {
            int mid = (ll + rr) / 2;

            if(nums[mid] > tar) {
                rr = mid;
            } else {
                ll = mid + 1;
            }
        }

        if(nums[ll] == target) {
            ret[0] = ll;
        } else {
            goto FAIL;
        }
    }

    *returnSize = 2;
    return ret;

FAIL:
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    return ret;
}