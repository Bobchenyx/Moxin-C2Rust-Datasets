bool canThreePartsEqualSum(int* A, int ASize){
    int i;
    int sum[50000] = {0};
    int flag = 0;
    int avg = 0;

    /* 1. 保存累加值到sum[]中 */
    sum[0] = A[0];
    for (i = 1; i < ASize; i++) {
        sum[i] = sum[i-1] + A[i];
    }    

    /* 2. 不可被3整除直接返回false */
    if (sum[ASize - 1] % 3 != 0) {
        return false;
    }

    /* 3. 再遍历一遍sum[], 找到sum[ASize - 1]/3和sum[ASize - 1]*2/3 */
    avg = sum[ASize - 1] / 3;
    for (i = 0; i < ASize; i++) {
        if (sum[i] == avg * (flag + 1)) {
            flag++;
            if (flag == 2 && i < (ASize-1)) {
                return true;
            }
        }
    }    
    
    return false;
}