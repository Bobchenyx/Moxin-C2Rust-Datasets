#define MIN(a, b) ((a) < (b) ? (a) : (b))

int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    int i;
    int *cnt;
    int idx = 0;
    int len;
    int min = deckSize;

    if (deckSize <= 1) {
        return false;
    }

    qsort(deck, deckSize, sizeof(int), compare);

    len = deck[deckSize-1] - deck[0] + 1;
    cnt = (int *)calloc(len, sizeof(int));

    for (i = 0; i < len; i++) {
        cnt[i] = 1;
    }

    for (i = 1; i < deckSize; i++) {
        if (deck[i] == deck[i-1]) {
            cnt[idx]++;
            continue;
        }

        idx++;
    }

    for (i = 0; i < len; i++) {
        min = MIN(min, gcd(min, cnt[i]));
//        printf("min=%d cnt[%d]=%d\n", min, i, cnt[i]);
        if (min == 1) {
            free(cnt);
            return false;
        }
    }

    for (i = 0; i < len; i++) {
        if (cnt[i] % min != 0) {
            free(cnt);
            return false;
        }
    }

    free(cnt);
    return true;
}