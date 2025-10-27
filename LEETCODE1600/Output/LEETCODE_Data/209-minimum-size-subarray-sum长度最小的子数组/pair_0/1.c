int minSubArrayLen(int s, int* nums, int numsSize){
    int leftWin = 0;
    int rightWin = 0;
    int len = 0xFFFF;
    long sum = 0;
    //printf("------- \n");
    //printf("%lu \n", numsSize);
    while (rightWin <  numsSize) {
        sum += (long)nums[rightWin];
        while (sum >= (long)(s + nums[leftWin])) {
            sum -= (long)nums[leftWin];
            leftWin++;
        }
        //printf("%lu ,%lu  \n", leftWin, rightWin);
        if ((sum >= s) && (len >= (rightWin - leftWin + 1))) {
                len = rightWin- leftWin + 1;
                //printf("%lu \n", len);
        }
        rightWin++;
    }
    if ((numsSize != 0) && (len == 0)) {
        len++;
    }
    return len != 0xFFFF ? len : 0;
}