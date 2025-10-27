int cmpfir(const void **ele1, const void **ele2)
{
    int **p1 = (int **)ele1;
    int **p2 = (int **)ele2;
    if (p1[0][0] < p2[0][0]) {
        return -1;
    } else if (p1[0][0] == p2[0][0]) {
        return 0;
    } else {
        return 1;
    }
}
int cmpsec(const void **ele1, const void **ele2)
{
    int **p1 = (int **)ele1;
    int **p2 = (int **)ele2;
    if (p1[0][1] < p2[0][1]) {
        return -1;
    } else if (p1[0][1] == p2[0][1]) {
        return 0;
    } else {
        return 1;
    }
}
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int minRow, minCol;
    if (ops == NULL || opsSize == 0 || *opsColSize == 0) {
        return m * n;
    }
    
    qsort(ops, opsSize, sizeof(int) * 2, cmpfir);
    minRow = ops[0][0];
    qsort(ops, opsSize, sizeof(int) * 2, cmpsec);
    minCol = ops[0][1];
    return minRow * minCol;
}