bool isHappy(int n){
    int yuShu, nextNum;
    if ((n == 1) || (n == 7)) {
        return true;
    } else if (n < 10) {
        return false;
    }
    nextNum = 0;
    while (n != 0) {
        yuShu = n % 10;
        nextNum += yuShu * yuShu;
        n = n / 10;
    }

    return isHappy(nextNum);
}