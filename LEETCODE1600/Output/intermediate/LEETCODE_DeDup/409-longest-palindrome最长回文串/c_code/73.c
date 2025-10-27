int longestPalindrome(char * s){
    int nums[128] = {0};
    int i = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        nums[s[i]]++;
    }

    int ret = 0;
    int flag = 0; //有奇数则为1
    for (i = 0; i < 128; i++) {
        if (nums[i] % 2 == 0) {
            ret += nums[i]; 
        } else {
            ret = ret + nums[i] - 1;
            flag = 1;
        }
    }

    if (flag == 1) {
        ret++;
    }
    return ret;
}