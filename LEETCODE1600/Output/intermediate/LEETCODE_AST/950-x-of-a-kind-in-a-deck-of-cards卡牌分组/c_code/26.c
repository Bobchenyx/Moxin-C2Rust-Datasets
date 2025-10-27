int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int gcd(int m, int n)
{
    int r;
    while (n) {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deckSize < 2) {
        return false;
    }

    qsort(deck, deckSize, sizeof(int), cmp);
    int flag = 0;
    int i, j;

    for (i = 0; i < deckSize; ) {
        for (j = i + 1; j < deckSize && deck[j] == deck[i]; j++) {
            ;
        }
        if (flag) {
            if (gcd(j - i, flag) < 2) {
                return false;
            }
        }
        flag = j - i;
        i = j;
    }

    return true;
}