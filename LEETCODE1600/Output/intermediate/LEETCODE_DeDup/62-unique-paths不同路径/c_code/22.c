// 1.0 Recursion implementation
int uniquePaths(int m, int n) {
    // 注意：这里从1开始
    return (m == 1 || n == 1) ? 1 : uniquePaths(m - 1, n) + uniquePaths(n - 1, m);
}