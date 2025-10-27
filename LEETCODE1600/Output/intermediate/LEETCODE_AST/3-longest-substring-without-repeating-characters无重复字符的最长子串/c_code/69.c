int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    if (length == 1) {
        return length;
    }
    char *head = NULL, *rear = NULL;
    int size = 0, maxSize=0;
    head = rear = s;
    while ( s + length > rear) {
        int i, is_repeat_char = 1;
        for (i = 0; head + i < rear; i++) {
            // 在前面字符串  出现重复字符
            // 将head移到重复位置的后一个位置，跳出本次循环
            if ( *(head + i) == *rear && head + i != rear) {
                head = head + size;
                is_repeat_char = 1；
                break;
            } else {
                // 没有出现重复字符
                is_repeat_char = 0;
            }
        }
        // 如果没有出现重复的字符
        if (is_repeat_char == 0) {
            size = i+1;
        } else { 
            size = i;
        }
        rear++;
        if (maxSize < size) { maxSize = size;}
    }
    if (maxSize < size) { maxSize = size;}
    return maxSize;
}