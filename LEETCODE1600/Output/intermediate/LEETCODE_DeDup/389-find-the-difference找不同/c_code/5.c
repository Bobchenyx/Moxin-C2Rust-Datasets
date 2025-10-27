int comp(const void *p1,const void *p2)
{
    return strcmp(p1, p2);
}
//或者这样写比较函数
/*
void comp(const void *p1,const void *p2)
{
    return strcmp(*(char *)p1, *(char *)p2);
}
*/
char findTheDifference(char * s, char * t){
    //排序，同时遍历找不同
    int lens = strlen(s), lent = strlen(t);
    qsort(s, lens, sizeof(char), comp);
    qsort(t, lent, sizeof(char), comp);
    for(int i = 0; i < lens; i++){
        if(s[i] != t[i]) return t[i];
    }
    return t[lent - 1];
}