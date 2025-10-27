int lengthOfLongestSubstringTwoDistinct(char * s){
    int charNum      = 0;    //窗口内字符串种类
    int hashSet[128] = {0};  //窗口内字符状态
    int maxLen       = 0;
    int i            = 0;    //左边界
    int j            = 0;    //右边界

    while (s[i] != '\0' && s[j] != '\0') {        
        if ((hashSet[s[j]] == 0) && (charNum < 2)) {
            /* 窗口内最多只有一种字符，即将新加入一种字符 */
            hashSet[s[j]]++;
            j++;
            charNum++;
        } else if (hashSet[s[j]] != 0)  {
            /* 窗口内新加已存在字符 */
            hashSet[s[j]]++;
            j++;
        } else if ((hashSet[s[j]] == 0) && (charNum = 2)) {
            /* 窗口内已存在两类字符，即将新加入一类新字符 */
            while (charNum == 2) {
                hashSet[s[i]]--;
                i++;
                if (hashSet[s[i - 1]] == 0) {
                    charNum--;
                }
            }
        }        
        /* 应该没有其他情况了 */
        
        maxLen = ((maxLen > (j - i)) ? maxLen : (j - i));
    }

    return maxLen;
}