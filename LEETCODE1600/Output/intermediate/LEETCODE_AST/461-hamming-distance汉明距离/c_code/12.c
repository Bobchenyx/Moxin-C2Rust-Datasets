int hammingDistance(int x, int y) {
        int a = 0;
        for (int i = x ^ y; i; i >>= 1)
            if (i & 1)
                ++a;
        return a;
    }