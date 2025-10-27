int lengthOfLongestSubstring(char * s){
    int head = 0,tail = 0;
    int step=0,length=0,length_new=0,i = 0;
    step = strlen(s);
    while(step--){
        for(i=tail;i>head;i--){
            if(*(s+i-1)==*(s+tail)){
                head = i;
                break;
            }
        }
        length_new = tail-head+1;
        if(length_new>length) //若新的长度大于记录则替换
            length = length_new; 
        tail++;
    }
    return length;
}