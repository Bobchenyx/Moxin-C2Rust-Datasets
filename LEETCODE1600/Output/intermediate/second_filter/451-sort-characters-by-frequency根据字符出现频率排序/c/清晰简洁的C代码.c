char * frequencySort(char * s){
    int len = strlen(s);
    if (len <= 2)
        return s;
    int count[128] = {0}; //ascii字符串最大为128
    for (int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    int cmp(const void *p1, const void *p2) {
        char c1 = *(char*)p1;
        char c2 = *(char*)p2;
        //按字符出现次数从大到小排列，但如果次数相等，则按字符本身的从小到大排列
        return count[c1] == count[c2] ?  c1 > c2 : count[c1] < count[c2]; 
    }
    qsort(s, len, sizeof(char), cmp);
    return s;
}