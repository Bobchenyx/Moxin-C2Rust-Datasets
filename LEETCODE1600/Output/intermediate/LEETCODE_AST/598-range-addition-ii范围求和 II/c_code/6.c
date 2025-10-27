int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int i, j;
    int min_c = m, min_r = n;
    for(i = 0;i < opsSize;i++)
    {
        if(ops[i][0] < min_c)
        {
            min_c = ops[i][0];
        }
        if(ops[i][1] < min_r)
        {
            min_r = ops[i][1];
        }
    }
    return min_c * min_r;

}