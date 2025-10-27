bool check(int x, int y, int z) {
    int init = x - y;
    int delta = init;
    while (x - delta != init && x - delta != 0) {
        if (delta == z || delta + y == z || delta + x == z) {
            return true;
        }
        if (delta > y) {
            delta = delta - y;
        } else {
            delta = x - (y - delta);
        }
    }
    return false;
}

bool canMeasureWater(int x, int y, int z){
    if (x == z || y == z || x + y == z || abs(x - y) == z || z == 0) {
        return true;
    }
    if (x + y < z) {
        return false;
    }
    if (x > y) {
        return check(x, y, z);
    } else {
        return check(y, x, z);
    }
}