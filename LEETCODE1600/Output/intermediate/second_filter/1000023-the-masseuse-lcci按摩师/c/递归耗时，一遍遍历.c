int massage(int* nums, int numsSize){

    
    if (numsSize <= 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        return nums[0] >= nums[1] ? nums[0] : nums[1];
    } else if (numsSize == 3) {
        return nums[0]+nums[2] >= nums[1] ? nums[0]+nums[2] : nums[1];
    } else if (numsSize == 4) {
        int a = nums[0]+nums[2] >= nums[1]+nums[3] ? nums[0]+nums[2] : nums[1]+nums[3];
        int b = nums[0]+nums[3];
        return a>=b ? a : b;
    } else {
        //递归思路存在大量的重复计算，时间超时。
        // int a = massage(nums, numsSize-2);
        // int b = massage(nums, numsSize-1);
        // int c = nums[numsSize-1];
        // if (a+c > b) {
        //     return a+c;
        // } else {
        //     return b;
        // }

        int a = massage(nums, 3);   //前两个最大值
        int b = massage(nums, 4);   //前1个最大值
        for (int i=5; i<=numsSize; i++) {
            //当前值
            int c = nums[i-1];
            //比较大小
            if (a+c > b) {
                //交换值
                int t = b;
                b = a+c;
                a = t;
            } else {
                //
                a = b;
            }
        }
        return a>b ? a : b;
    }
}