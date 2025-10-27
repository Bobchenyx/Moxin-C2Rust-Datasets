# define INT_MAX 100
char * longestCommonPrefix(char ** strs, int strsSize){
    char *arr = (char *)malloc(sizeof(char) * 1000);
    if (strsSize == 0) {
        arr[0] = '\0';
        return arr;
    }
    if (strsSize == 1) {
        return strs[0];
    }
    int flag = 0;  //标记比较值的角标
    int len =strlen(strs[0]);

    for (int i = 0; i < len; i++) {//第一个字符串的角标
        arr[flag] = strs[0][i];  //将第一个字符串的第一个字符存入            
        for (int j = 1; j < strsSize; j++) {  //比较其他字符串的相应角标依次比较
            if (arr[flag] == strs[j][i]) {
                continue;

            } else {
                arr[flag] = '\0';
                return arr;
            }
        }
        //说明各字符串的相应位置的字符相等，将下一个字符存入，循环
        flag++;
    }
    arr[flag] = '\0';
    return arr;
}