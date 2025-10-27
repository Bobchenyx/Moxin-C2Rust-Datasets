int subtractProductAndSum(int n){
    int product = 1;
    int sum = 0;
    int temp = 0;
    while(n){
        temp = n % 10;
        if(product != 0){
            product *= temp;
        }
        sum += temp;
        n /= 10;
    }
    return product - sum;
}