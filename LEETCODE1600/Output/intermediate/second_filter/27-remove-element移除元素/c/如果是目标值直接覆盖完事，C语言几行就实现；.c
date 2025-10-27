/**
  * -*- coding: utf-8 -*-
  *  @Time    : 2019/8/12 15:19
  *  @Author  : 奥利波德
  *  @FileName: removeElement.c
  *  @Software: CLion
  *  @Blog    ：https://blog.csdn.net/qq_44265507
 */
int removeElement(int* nums, int numsSize, int val){

    int len=0;
    for (int j = 0; j < numsSize; ++j) {
        if(nums[j]!=val){
            nums[len++]=nums[j];
        }
    }
    return len;
}