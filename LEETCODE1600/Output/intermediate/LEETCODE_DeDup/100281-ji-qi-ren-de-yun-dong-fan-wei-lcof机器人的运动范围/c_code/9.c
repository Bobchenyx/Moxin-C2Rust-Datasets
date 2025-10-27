int moveOne(int m, int n, int k, int i, int j, int *arrived){
    int sum = 0;
    int count = 1;
    if( (i < 0 || i == m) || ( j < 0 || j == n)) {
        return 0;
    }
    if(arrived[i * n + j] == 1) {
        return 0;
    }
    sum = i % 10 + i / 10 + j % 10 + j / 10;
    if( sum > k) {
        return 0;
    }
    // check if could arrived
    // check_arrived(arrived, i, j);
    arrived[i * n + j] = 1;
    count += moveOne(m, n, k, i + 1, j, arrived);
    count += moveOne(m, n, k, i, j + 1, arrived);
    return count;
}

int movingCount(int m, int n, int k){
    int *arrived = (int *)malloc(sizeof(int) * m * n);
    int count = 0;
    memset(arrived, 0, m * n * sizeof(int));

    count = moveOne(m,n,k,0,0,arrived);

    free(arrived);
    return count;
}