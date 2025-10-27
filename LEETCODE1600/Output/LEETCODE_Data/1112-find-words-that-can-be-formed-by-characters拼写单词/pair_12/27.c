int countCharacters(char ** words, int wordsSize, char * chars){
    int charsSize=strlen(chars);
    if (!wordsSize||!charsSize) return 0;/*特殊情况*/
    int hashTable[26]={0};/*创建并初始化hashTable*/
    for (size_t i=0;i<charsSize;i++)/*将chars中的每个字符装进表里，重复的计数+1*/
    {
        int pos=chars[i]-'a';
        hashTable[pos]+=1;
    }
    int charsNum=0;/*这是最终的返回值*/
    for (size_t i=0;i<wordsSize;i++)
    {
        int flag=0;/*标记*/
        char *nowword=words[i];
        int wordLen=strlen(nowword);
        if (wordLen>charsSize) continue;/*此次循环字符串长度比chars大
                                        则不用考虑，直接开始下一次循环*/
        int countTable[26]={0};/*记录该次循环的字符串每种字符数量，每次循环要初始化*/
        for (size_t j=0;j<wordLen;j++)/*判断chars里是否有每种字符且数量是否足够*/
        {
            int nowpos=nowword[j]-'a';
            if (countTable[nowpos]<hashTable[nowpos]) countTable[nowpos]++;
            else {flag=1;break;}
        }
        if (!flag) charsNum+=wordLen;/*若标记没变则返回值要加上此次循环的字符串长度*/
    }
    return charsNum;
}