int fib(int N){
    if (N == 0) return 0;
    if (N < 3) return 1;
    // f1 f0 f-1
    int tmp[3] = {1, 1, 0};
    int res[3] = {1, 0, 1};
    int multi_support;
    int tmp0_back;

    for (; N != 0; N >>= 1)
    {
        // one cycle 9 multiplication and 6 addition
        // logn cycles
        if (N & 1) {
            multi_support = tmp[1]*res[1];
            res[0] = tmp[0]*res[0] + multi_support;
            res[1] = tmp[0]*res[1] + tmp[1]*res[2];
            res[2] = multi_support + tmp[2]*res[2];
        }
        multi_support = tmp[1] * tmp[1];
        tmp0_back = tmp[0];
        tmp[0] = tmp[0]*tmp[0] + multi_support;
        tmp[1] = tmp[1] * (tmp0_back + tmp[2]);
        tmp[2] = multi_support + tmp[2]*tmp[2];
    }
    return res[1];
}