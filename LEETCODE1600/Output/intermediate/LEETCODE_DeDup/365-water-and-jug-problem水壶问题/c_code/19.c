bool canMeasureWater(int x, int y, int z){
    int s = fmin(x,y);
    int l = fmax(x,y);

    if (z > s+l) return false;
    if (z == s || z == l || z == s+l) return true;

    if (s == 0) return (z == l);

    if (z > l) {
        return canMeasureWater(s, l, z-l);
    }

    if ((z > s && z < l) || (z < s)) {
        int left = l;
        while (left > 0) {
            left = (left >= s) ? (left - s) : (left + l - s);
            if (left == z) return true;
        }
        return false;
    }

    return false;
}