bool isPalindrome(int x){
    if (x < 0) return false;
    if (x == 0) return true;

    unsigned int val = 0;
    int rem = 0;
    int backUp = x;
    while (x > 0) {
        rem = x % 10;
        x = x / 10;
        val = val * 10 + rem;
    }

    if (val != backUp) return false;
    return true;
}