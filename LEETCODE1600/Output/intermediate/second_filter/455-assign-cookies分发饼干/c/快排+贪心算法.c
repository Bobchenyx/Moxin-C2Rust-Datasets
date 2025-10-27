int cmpfun(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0;
    int j = 0;

    if(gSize == 0 || sSize == 0){
        return 0;
    }
    qsort(g, gSize, sizeof(int), cmpfun);
    qsort(s, sSize, sizeof(int), cmpfun);

    while(i < gSize && j < sSize){
        if(s[j++] >= g[i]){
            i++;
        }
    }

    return i;
}