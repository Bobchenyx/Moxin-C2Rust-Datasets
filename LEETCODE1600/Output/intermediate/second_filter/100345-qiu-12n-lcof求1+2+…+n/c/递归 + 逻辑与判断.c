int sumNums(int n){
    int sum = 0;
    n > 0 && (sum = sumNums(n - 1) + n);
    return sum;
}