int cmp(const void ** _a, const void **_b){
    char **a = (char **)_a;
    char **b = (char **)_b;

    return strlen(*a) - strlen(*b);
}


int minimumLengthEncoding(char ** words, int wordsSize){
    int old_len=0, cut_len=0;
    int i,j,hide_cnt=0,len;
    char *pos;

    /*当数组时， 如下使用  qsort(arr,arr_len,sizeof(int),cmp)*/
    qsort(words, wordsSize, sizeof(char*),cmp);

    for(i=0;i<wordsSize-1;i++){

        len = strlen(words[i]);
        old_len += len;
        for(j=i+1;j<wordsSize;j++){
            /*在words[i]中找words[j], 找到则返回在words[i]中指针，所以可以直接对返回值取strlen*/
            pos = strstr(words[j], words[i]);
            if(pos != NULL && strlen(pos) == strlen(words[i])){
                cut_len += strlen(words[i]);
                hide_cnt += 1;
                break;
            }
        }
    }
    old_len += strlen(words[i]);

    return old_len -cut_len + wordsSize-hide_cnt;
}