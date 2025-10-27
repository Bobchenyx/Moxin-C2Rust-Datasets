int lengthOfLongestSubstring(char * s){
    int a = strlen(s);
    if(a == 1)
        return a;
    int maxsize, size;
    char tag[128] = {0};
    char *front, *rear;
    front = rear = s;
    maxsize = size = 0;
    while(rear < s + a)
    {
        if(!tag[*rear])         //说明*rear未曾在之前的子串序列中出现
        {
            tag[*rear] = 1;
            size++;
            rear++;
        }
        else
        {
            if(maxsize < size)
                maxsize = size;         //每需要抛弃前面子串时就要更新maxsize
            while(*front != *rear)
            {
                tag[*front] = 0;
                front++;
                size--;
            }                   //通过循环找到之前已经出现过的元素x
            front++;
            rear++;
        }
    }
    if(maxsize < size)
    	maxsize = size;         //未出现重复元素就到达字符数组尾部时，需要额外更新一次maxsize
    return maxsize;    
}