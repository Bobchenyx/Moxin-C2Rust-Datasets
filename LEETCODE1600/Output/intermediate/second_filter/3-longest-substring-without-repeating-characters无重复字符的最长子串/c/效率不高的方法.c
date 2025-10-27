int lengthOfLongestSubstringDF(char *s, int head){
    if(s[head] == '\0') return 0; /*递归出口*/
    int index = head, length = 0;
    int isRepeat = 0;
    for(; s[index] != '\0'; index ++){
        for (int i = head; i < index; i++)
        {
            if(s[i] == s[index]) {
                isRepeat = 1;/* 已经重复了 */
                break;
            }
        };
        if(isRepeat) break;
        else length ++;
    }
    int subLength = lengthOfLongestSubstringDF(s, head + 1);
    return length > subLength?length :subLength;
}