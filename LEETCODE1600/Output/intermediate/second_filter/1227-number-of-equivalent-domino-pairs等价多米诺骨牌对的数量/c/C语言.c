int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int tmp;
    int ret = 0;
    int count[100] = {0};

    for (int i = 0; i < dominoesSize; i++) {
        qsort(dominoes[i], dominoesColSize[i], sizeof(int), cmp);
    }
    // 转化成二位数，然后统计每个的个数，只统计出现次数>1的，结果是组合数C（2，n）
    for (int i = 0; i < dominoesSize; i++) {
        tmp = dominoes[i][0] * 10 + dominoes[i][1];
        count[tmp]++;
    }
    for (int i = 1; i < 100; i++) {
        if (count[i] > 1) {
            ret += (count[i] - 1) * count[i] / 2;
        }
    }
        
    return ret;
}