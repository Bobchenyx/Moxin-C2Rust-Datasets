int massage(int* nums, int numsSize){
    if (numsSize == 0){
        return 0;
    }else if (numsSize == 1){
        return nums[0];
    }else if (numsSize == 2){
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }else if (numsSize == 3){
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    }

    int m1 = massage(nums + 2, numsSize - 2) + nums[0];
    int m2 = massage(nums + 1, numsSize - 1);

    if (m1 > m2){
        return m1;
    }else{
        return m2;
    }
}