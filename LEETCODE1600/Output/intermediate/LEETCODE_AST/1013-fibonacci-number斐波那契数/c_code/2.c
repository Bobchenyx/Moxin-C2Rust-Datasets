C []
int fib(int n){
    int curr = 0, next = 1;
    while (n-- > 0) {
        next = next + curr; // 辗转相加法，F(n) = F(n-1) + F(n-2)
        curr = next - curr; // 记录前一项，F(n-1) = F(n) - F(n-2)
    }
    return curr;
}