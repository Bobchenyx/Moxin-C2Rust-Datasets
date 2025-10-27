int lengthOfLongestSubstring(char * s){
    int prior = 0; //上次状态下最长子串的长度
    int left = 0;
    int dict[256] = {0}; //映射ASCII码
    int right = 1; //表示字符串中第right个字符
    int i;

    while(*s != '\0'){
        i = *s-0; //字符转换为整数
        if(dict[i] > left)    
            left = dict[i];
        dict[i] = right;
        prior = (prior>right-left)?prior:right-left; //right的值比对应的数组下标大1
        s++;
        right++;
    }
    return prior;
}