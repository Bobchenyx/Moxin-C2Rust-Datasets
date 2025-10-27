void reverseString(char* s, int sSize){
    //方法1.折半对调 从中间开始向两边逐次对调
    //方法2.直接首尾对调，省去了比较的时间；
    //执行用时 :60 ms, 在所有 C 提交中击败了77.51% 的用户
    //内存消耗 :13.5 MB, 在所有 C 提交中击败了94.43%的用户
    int mid = 0;
    int temp = 0;
    if(sSize == 0 || sSize ==1){
        s = s;
    }
    else{
        int start = 0;
        int fail = sSize - 1;
        for(;start < fail; start++,fail--){
            temp = s[start];
            s[start] = s[fail];
            s[fail] = temp;
        }
    }
}