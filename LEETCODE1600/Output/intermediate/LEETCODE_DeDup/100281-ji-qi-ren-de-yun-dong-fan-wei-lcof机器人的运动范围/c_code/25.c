int isReachable(int i, int j, int k) {
    if (i == 0 && j == 0) {
        return 1;
    }

    if (idSum(i, j) > k) {
        return 0;
    }

    return 1;
}

int idSum(int x, int y) { // 计算行坐标和列坐标的数位之和
    int res = 0;
    if (x >= 0 && x < 10) {
        res += x;
    } else if (x >= 10 && x < 100) {
        res += x/10 + x%10;
    } else if (x == 100) {
        res += 1;
    }

    if (y >= 0 && y < 10) {
        res += y;
    } else if (y >= 10 && y < 100) {
        res += y/10 + y%10;
    } else if (y == 100) {
        res += 1;
    }

    return res;
}

int movingCount(int m, int n, int k){
    int res = 0;
    int i;
    int j;

    int rflag[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rflag[i][j] = isReachable(i, j ,k);  // 遍历1：理论可达
        }
    }

    rflag[0][0] = 2;

    for (i = 0; i < m; i++) {  // 遍历2：实际可达
        for (j = 0; j < n; j++) {
            if (rflag[i][j] == 2) {
                if (i-1 >= 0) { // 标记为实际可达的条件：1.理论可达 2.上下左右存在实际可达
                    rflag[i-1][j] = (rflag[i-1][j] == 1) ? 2 : rflag[i-1][j];
                }
                if (i+1 < m) {
                    rflag[i+1][j] = (rflag[i+1][j] == 1) ? 2 : rflag[i+1][j];
                }
                if (j-1 >= 0) {
                    rflag[i][j-1] = (rflag[i][j-1] == 1) ? 2 : rflag[i][j-1];
                }
                if (j+1 < n) {
                    rflag[i][j+1] = (rflag[i][j+1] == 1) ? 2 : rflag[i][j+1];
                }
            } 
        }
    } 

    for (i = 0; i < m; i++) { // 遍历2：计算实际可达个数
        for (j = 0; j < n; j++) {
            if (rflag[i][j] == 2) {
                res++;
            }
        }
    }

    return res;
}