int calcSquare(int n){
    int res = 0 ;
    while (n > 0){
        res += ( n % 10) * ( n % 10);
        n = n / 10;
    }
    return res;
}

bool isHappy(int n){
    int fast = n, slow = n;
    do {
        fast = calcSquare(fast);
        fast = calcSquare(fast);
        slow = calcSquare(slow);
    } while ( fast != slow);
    return slow == 1;

}