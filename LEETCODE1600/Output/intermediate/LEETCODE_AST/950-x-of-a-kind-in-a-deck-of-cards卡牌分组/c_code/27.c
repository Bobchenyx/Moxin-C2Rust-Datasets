int gcd(int x, int y) {
    return x == 0 ? y : gcd(y%x, x);
}

#define N 10000
bool hasGroupsSizeX(int* deck, int deckSize){
    int count[N]= {0};
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    int g = -1;
    for (int i = 0; i < N; i++) {
        if (count[i] > 0) {
            if (g == -1) {
                g = count[i];
            } else {
                g = gcd(g, count[i]);
            } 
        }
    }

    return g >= 2;
}