int sumNums(int n){
    return n == 1 ? 1 : sumNums(n - 1) + n;
}