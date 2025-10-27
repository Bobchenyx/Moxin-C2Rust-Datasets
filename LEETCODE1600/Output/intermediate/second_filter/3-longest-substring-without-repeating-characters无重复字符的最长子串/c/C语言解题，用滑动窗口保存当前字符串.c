int lengthOfLongestSubstring(char * s){
    if(s[0] == '\0')
    return 0;
    if(s[1] == '\0')
    return 1;
    int max=0, i=0, j;//i为滑动窗口前端，j为后端
    bool flag;//用来判断当前字符是否在窗口内
    for(j=1; s[j]!='\0'; j++){
        flag = false; //每增加一个字符时都假设为“不在”
        for(int k=i; k<j; k++){ //判断新的字符在不在已有窗口内
            if(s[k] == s[j]){ //如果在的话
                max = max>(j-i) ? max:(j-i); //比较当前最大长度
                i = k+1; //将i放到窗口内的重复字符的下一位
                flag = true; //标记存在
                break;
            }
        }
        if(!flag){ //如果当前字符不在已有窗口内，修改最长长度
            max = max>(j-i+1) ? max:(j-i+1);
        }
    }
    return max;
}