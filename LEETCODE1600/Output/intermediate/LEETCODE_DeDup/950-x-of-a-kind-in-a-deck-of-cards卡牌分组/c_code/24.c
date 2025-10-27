int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
}HashNode;

HashNode *head;

void initHashData(int* deck, int deckSize) {
    int i;
    HashNode *fnd, *new;
    for (i = 0; i < deckSize; i++) {
        HASH_FIND(hh, head, &deck[i], sizeof(int), fnd);
        if (fnd) {
            fnd->cnt++;
        } else {
            new = (HashNode *)calloc(1, sizeof(HashNode));
            new->key = deck[i];
            new->cnt = 1;
            HASH_ADD(hh, head, key, sizeof(int), new);
        }
    }
    return;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int ret, i;
    HashNode *cur, *tmp;

    initHashData(deck, deckSize);

    ret = 0;
    HASH_ITER(hh, head, cur, tmp) {
        if(ret == 0) {
            ret = cur->cnt;
            continue;
        }
        ret = gcd(cur->cnt, ret);
    }

    HASH_ITER(hh, head, cur, tmp) {
        HASH_DEL(head, cur);
        free(cur);
    }

    return (ret > 1)?true:false;
}