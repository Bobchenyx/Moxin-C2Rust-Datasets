int lengthOfLongestSubstring(char * s){
    int length = strlen(s);

    //如果字符串为空，或者只有一个字符，则返回0和1
    if(length==0 || length==1)return length;
    
    //maxlen为最长子串长度
    int maxlen=1;

    int head = 0;
    int rear = 1;
    int pointer = 0;
    int len=1;

    while(rear < length)
    {
        while(pointer != rear)
        {
            if(s[pointer] != s[rear]) pointer++;
            else
            {
                head++;
                pointer = head;
                rear = head+1;
                len=1;
                //当head=length-1，pointer=head，rear=length时
                //虽然已经不满足rear<length，但是仍然要先完成内层while才能跳出外层while
                if(rear==length)return maxlen;
            }
        }
         len++;
         if(maxlen<len)maxlen=len;
         rear++;
         pointer = head;
    }
    return maxlen;
}