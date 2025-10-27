int lastRemaining(int n, int m){
    int res;
    if (n <= 1) {
        res = 0;
    } else {
        res = (m + lastRemaining(n - 1, m)) % n; 
    }
    return res;
}