int hammingDistance(int x, int y)
{
    int dis = 0;
    int xor = x ^ y;
    while (xor)
    {
        if (xor % 2 != 0)
            dis++;
        xor /= 2;
    }
    return dis;
}