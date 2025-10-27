#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

char * longestPalindrome(char * s){
    int max = 0;
    int i,j,k,head = 0;
    char *ret = "";

    for (i = 0; i < strlen(s); i++) {

        //如果此时最长已经不可能大于max了，那后面就不需要遍历了
        if (max >= 2 * (strlen(s) - i) - 1)
            break;

        //奇数回文串情况
        for(j = 0; j <= i; j++ ) {
            if ( s[i - j] != s[i + j] )
                break;
        }
        //偶数回文串情况
        for(k = 0; k <= i; k++ ) {
            if ( s[i - k] != s[i + k + 1] )
                break;
        }
        
        //取max、奇数回文情况、偶数回文情况的最大值
        if(max < MAX(2 * j - 1, 2 * k)) {
            //记录该回文的头部位置
            max = MAX(2 * j - 1, 2 * k);
            head = i - (max - 1) / 2;
        }
    }

    //截断原字符串
    ret = s + head;
    ret[max] = '\0';

    return ret;
}