#define END -2

char * reverseWords(char * s){
    
    int i = 0;
    int j = 0;
    int flag = 0;
    int sLen = strlen(s);
    while (s[j] != '\0') {
        if (s[j] != ' ') {
            s[i++] = s[j++];
            flag = 1;
        }
        else {
            if (flag == 1) {
                s[i++] = s[j++];
                flag = 0;
                continue;
            }
            j++;
        }
    }
    if (i >= 1 && s[i - 1] == ' ') {
        s[i - 1] = '\0';
        i--;
    }
    else {
        s[i] = '\0';
    }
    // 下面进行整体反转
    int l = 0;
    int r = i - 1;
    while (l < r) {
        char tmp;
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    // 下面进行单词反转
    int start = 0;
    int end = END;
    int k = 0;
    for (; k <= i; k++) {
        if (s[k] == ' ' || s[k] == '\0') {
            start = end + 2;
            end = k - 1;
            while (start < end) {
                char tmp;
                tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                start++;
                end--;
            }
            end = k - 1;
        }
    }
    return s;
}