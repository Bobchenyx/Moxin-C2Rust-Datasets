int lengthOfLongestSubstring(char * s){
    if(s[0] == '\0')//""是个什么？ NULL ?s == ""
        return 0;

    int count[128] ;//C语言无bool 得用int记录位置
    for(int i = 0;i<128;i++)
        count[i] = -1;

    int max = 1;//至少长度为1
    //ASCLL表长128 a在97（0开始）&& ((pos>=97 && pos<=122) ||(pos>=65 && pos<=90))){//且不被其他字符打断
    //题目未考虑
    for( int i = 0,curStart = 0;i < strlen(s); i++){  
        int pos = s[i] - 'a' +97;
        if(count[pos] == -1 || count[pos] < curStart){
            count[pos] = i;
            max =  max > i - curStart +1 ? max:i - curStart +1 ;
        }
        else{
                curStart = count[pos] + 1;
                count[pos] = i;
        }
    }
    return max;
}