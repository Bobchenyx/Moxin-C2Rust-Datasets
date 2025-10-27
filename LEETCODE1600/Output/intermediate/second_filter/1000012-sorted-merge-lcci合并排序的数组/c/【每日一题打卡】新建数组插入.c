void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    // 排序过的数组
    int sorted[m + n];

    // 记录A、B两个数组已排序过的位置
    // 相当于指针的作用
    int pa, pb, cur;
    pa = 0;
    pb = 0;

    while (pa < m && pb < n) {
        if (A[pa] < B[pb]) {
            cur = A[pa];
            pa += 1;
        } else {
            cur = B[pb];
            pb += 1;
        }
        
        sorted[pa + pb - 1] = cur;
    }

    while (pa < m) {
        sorted[pa + pb] = A[pa];
        pa += 1;
    }

    while (pb < n) {
        sorted[pa + pb] = B[pb];
        pb += 1;
    }

    for (cur=0; cur<m+n; cur++) {
        A[cur] = sorted[cur];
    }
}