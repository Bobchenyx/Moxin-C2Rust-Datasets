int cmp (const void* a, const void* b)
{
    const int *pa = *(const int **)a;
    const int *pb = *(const int **)b;
    return pa[1] - pb[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    int i,j;
    int length = 1;
    qsort(pairs,pairsSize,sizeof(int *), cmp);
    for(i = 0; i< pairsSize; i++) {
    }
    j = 0;
    for(i = 0; i< pairsSize - 1; i++) {
        if(pairs[j][1] < pairs[i + 1][0]) {
            j = i + 1;
            length++;
        }
    }
    *pairsColSize = 2;
    return length;
}