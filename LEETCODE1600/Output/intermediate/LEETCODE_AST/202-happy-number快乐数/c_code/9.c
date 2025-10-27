bool isHappy(int n){
    if(n == 1 || n ==7)
        return 1;
    if(n < 10)
        return 0;
    int sum = 0;
    do{
        sum += (n % 10) * (n % 10);
        n /= 10;
    }while(n != 0);
    return isHappy(sum);
}