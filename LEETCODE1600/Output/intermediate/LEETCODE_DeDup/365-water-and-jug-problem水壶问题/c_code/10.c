int gcd(int a,int b)
{
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a == b) {
        return a;
    }
    int mod = a % b;
    while (mod != 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}
bool canMeasureWater(int x, int y, int z){
    if (x == z || y == z || x + y == z) {
        return true;
    }
    if (gcd(x,y) == 0 || x + y < z) {
        return false;
    }
    return (z % gcd(x, y) == 0);
}