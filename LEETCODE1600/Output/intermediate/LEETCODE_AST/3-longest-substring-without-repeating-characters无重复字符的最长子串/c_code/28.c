int lengthOfLongestSubstring(char * s){
    //用于储存目前最长字串
    int prior = 0;
    //用于定位目前不重复字符串的起始字符左边一个字符（即最近一个出现重复的字符）
    int left = 0;
    //用数组构建一个哈希表，存储该字符最近出现位置，若为0，则表示没有出现过，并且为256而不为128是因为此处是ASCII扩展字符集
    int dict[256] = {0};
    //目前所遍历的字符串的位置
    int right = 1;
    //存储目前字符的ASCII值
    int i;

    while (* s != '\0')
    {
        //获得目前字符的ASCII值
        i = * s - 0;

        //判断目前所遍历字符是否出现过
        if (dict[i] > left)
            //若出现过，则将目前不重复字符串起始位置之前的一位定位到该字符
            left = dict[i];

        //不论是否出现过，都更新该字母对应哈希表的值
        dict[i] = right;

        //判断目前不重复字符串长度是否比出现过的最长不重复字符串长
        prior = (prior>right-left)? prior : right-left;

        //将指针指向下一个字符
        s++;

        //更新为接下来要遍历的字符的位置
        right++;
    }

    return prior;
}