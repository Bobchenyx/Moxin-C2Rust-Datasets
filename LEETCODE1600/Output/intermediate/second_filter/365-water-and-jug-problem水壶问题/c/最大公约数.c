int GetGCD(int a, int b)
{
    if (a == b) {
        return a;
    }
    if (a > b) {
        return GetGCD(a - b, b);
    }
    if (a < b) {
        return GetGCD(b - a, a);
    }
    return 0;
}

bool canMeasureWater(int x, int y, int z)
{
    if (x + y < z) {
        return false;
    }

    if ((x == 0) || (y == 0)) {
        return (z == 0);
    }

    int gcd = GetGCD(y, x);
    return (z % gcd == 0);
}