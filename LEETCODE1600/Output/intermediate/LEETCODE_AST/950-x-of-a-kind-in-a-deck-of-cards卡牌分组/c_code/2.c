int cmp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    }

    if (*(int*)a == *(int*)b) {
        return 0;
    }

    if (*(int*)a < *(int*)b) {
        return -1;
    }

    return 0;
}

bool hasGroup(int* deck, int deckSize, int X)
{
    int left = 0;
    int right = 0;
    for (int i = 0; i < deckSize; i++) {
        if (i >= right) {
            left = i;
            right = i + X;
        }
        //printf("left = %d, right = %d, i = %d\n", left, right, i);
        if (i >= left && i < right) {
            if (deck[i] != deck[left]) {
                return false;
            }
        }
    }

    return true;

}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deck == NULL || deckSize <= 1) {
        return false;
    }

    qsort(deck, deckSize, sizeof(int), cmp);
    int X = 0;
    bool isOk = false;
    if (deckSize % 2 == 0) {
        X = 2;
        isOk = hasGroup(deck, deckSize, X);
        if (isOk == true) {
            return true;
        } 
    }
    if (deckSize % 3 == 0) {
        X = 3;
        isOk = hasGroup(deck, deckSize, X);
        if (isOk == true) {
            return true;
        } 
    }
    if (deckSize % 5 == 0) {
        X = 5;
        isOk = hasGroup(deck, deckSize, X);
        if (isOk == true) {
            return true;
        } 
    }
    if (deckSize % 7 == 0) {
        X = 7;
        isOk = hasGroup(deck, deckSize, X);
        if (isOk == true) {
            return true;
        } 
    }

    return false;
}