char * reverseWords(char * s){
    int size = strlen(s);
    char* new_s = (char*)malloc(sizeof(int) * (size + 1));
    memset(new_s, 0, sizeof(int) * (size + 1));
    int i = size - 1, j = 0;  //i从后到前遍历s，j指向new_s新增字符
    int front = 0, rear = 0;  //遍历s过程中，rear指向一个word的最后一位，front指向同个word的第一位
    while (i >= 0) {
        if (s[i] != ' ') {
            if (rear == 0) {  //“前”一个字符是空格
                if (new_s[0]) new_s[j++] = ' '; //还没有单词入new_s时，不能插入空格，否则每隔一个单词插入一个空格
                rear = i;  //rear赋值，暂时不变，指向word的最后一位
            }
            if (i == 0) {  //特殊情况：s前面没有空格，此时需单独回头遍历直至空格或结束
                while (i < size && s[i] != ' ') {
                    new_s[j++] = s[i++];
                }
                break;
            }
        }
        else {
            if (rear != 0) {  //此时rear还保留着，说明“前”一个字符非空格
                front = i + 1;  //front赋值，指向word第一位
                while (front <= rear) {  //回头遍历到rear停止
                    new_s[j++] = s[front++];
                }
                rear = 0;  //rear置零
            }
        }
        i--;
    }
    return new_s;
}