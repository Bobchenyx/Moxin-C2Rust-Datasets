int reverse(int x){
    long y = 0;
    while (x != 0){
        int n = x % 10;
        y = y * 10 + n;
        x /= 10;
    }
    return (y > INT_MAX || y < INT_MIN) ? 0 : y;
}