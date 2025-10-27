int longestMountain(int* A, int ASize){
    if (ASize < 3) {
        return 0;
    }
    int max = 0;
    int l = 0;
    int r = 1;
    int updown = 0;
    while (r < ASize) {
        if (A[r - 1] == A[r]) {
            updown = 0;
            l = r;
        } else if (A[r - 1] < A[r]) {
            if (updown == 2) {
                l = r - 1;
            }
            updown = 1;
        } else {
            if (updown == 0) {
                l = r;
            } else {
                updown = 2;
                max = fmax(max, r - l + 1);
            }
        }
        r++;
    }
    return max;
}