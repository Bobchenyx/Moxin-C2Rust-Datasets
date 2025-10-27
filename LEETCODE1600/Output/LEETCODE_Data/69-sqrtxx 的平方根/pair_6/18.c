int mySqrt(int x){
    int left = 0;
    int right = x;

    if (x ==0 || x == 1)
        return x;
    while (right - left > 1) {
        int mid = (left + right)/2;
        if (mid > x/mid)
            right = mid;
        else
            left = mid;
    }
    return left;
}