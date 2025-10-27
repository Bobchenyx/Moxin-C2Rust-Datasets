char *reverseWords(char *s) {
    // 处理特殊情况
    while (s[0] == ' ')
        s += 1;
    if (s[0] == '\0')
        return s;

    int offset = 0, left = 0, right = 0;
    while (++right) {
        if (s[right] == ' ' || s[right] == '\0') {
            if (right == left) {    
                // 遇到连续空格
                offset += 1;    
            } else {
                // 遇到单词，将单词倒序，注意 offset          
                for (int i = 0; i < (right - left + offset + 1) / 2; i++) {
                    char tmp = s[left + i - offset];
                    s[left + i - offset] = s[right - 1 - i];
                    if (i >= offset)
                        s[right - 1 - i] = tmp;
                }
                // 注意补空格
                if (offset != 0)    
                    s[right - offset] = ' ';
            }
            // 将 left 指到下一个单词的开头
            left = right + 1;       
        }
        if (s[right] == '\0')
            break;
    }

    // 截断字符串
    right -= offset;
    s[right] = '\0';    
    // 将字符串倒序
    for (int j = 0; j < right / 2; j++) {
        char tmp = s[j];
        s[j] = s[right - 1 - j];
        s[right - 1 - j] = tmp;
    }
    return s;
}