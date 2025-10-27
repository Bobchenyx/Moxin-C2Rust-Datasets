int sumNums(int n){
    int sum = n;
    n && (sum += sumNums(n-1));
    return sum;
}