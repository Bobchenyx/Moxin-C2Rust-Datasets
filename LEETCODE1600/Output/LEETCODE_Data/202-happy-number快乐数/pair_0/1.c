int getSquare(int num) {
    int tmp = 0;
    int sum = 0;
    while (num > 0) {
        tmp = num % 10;
        sum = sum + tmp * tmp;
        num = num / 10;
    }
    return sum;
}

bool isHappy(int n){
    int slow = getSquare(n);
    int fast = getSquare(n);
    fast = getSquare(fast);
    
    while (slow != fast) {
        slow = getSquare(slow);
        fast = getSquare(fast);
        fast = getSquare(fast);
    }
    return slow == 1;
}