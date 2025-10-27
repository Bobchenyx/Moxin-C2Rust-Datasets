bool lemonadeChange(int* bills, int billsSize){
    if (bills[0] != 5) {
        return false;
    }
    int fiveCount = 1;
    int tenCount = 0;
    // int twentyCount = 0;
    for (int i = 1; i < billsSize; i++) {
        if (bills[i] == 5) {
            fiveCount++;
        }
        if (bills[i] == 10) {
            tenCount++;
            if (fiveCount > 0) {
                fiveCount--;
            } else {
                return false;
            }
        }
        if (bills[i] == 20) {
            if (tenCount > 0 && fiveCount > 0) {
                tenCount--;
                fiveCount--;
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}