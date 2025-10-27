int findComplement(int num){
    long n = (long)(log2(num) + 1);

    n = (int)pow(2, n);
    n = n - 1 - num;

    return n;
}