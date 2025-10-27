int divide(int dividend, int divisor){
    int flag = 1;
    int ans = 0;
    long long unsignDivid = (long long)llabs(dividend);
    long long unsignDivis = (long long)llabs(divisor);

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }
    if (divisor == 0) {
        return 0;
    }
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
        flag = -1;
    }
    while (unsignDivid >= unsignDivis) {
        long long scop = unsignDivis;
        int p = 1;
        while (unsignDivid >= scop << 1) {
            scop = scop << 1;
            p = (p << 1);
        }
        unsignDivid -= scop;
        ans += p;
    }

    return flag == -1 ? -ans : ans;
}