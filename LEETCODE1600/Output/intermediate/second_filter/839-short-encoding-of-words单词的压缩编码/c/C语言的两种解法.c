int minimumLengthEncoding(char ** words, int wordsSize){
    #define MAX_NODES (2000 * 7 + 10)
    #define MAX_CHARS (26 * 2 + 2)
    int trieP[MAX_NODES][MAX_CHARS] = {0};
    int color[MAX_NODES] = {0};
    int k  = 1;
    for( int i = 0; i < wordsSize; i++ ) {
        int ilen = strlen(words[i]);
        int p  = 0;
        int nk = 0;
        for( int j = ilen - 1; j >= 0; j-- ) {
            int c  = words[i][j] - 'a';
            if( trieP[p][c] == 0 ) {
                trieP[p][c] = k;
                k++;
                nk = 1;
            }
            color[p] = 0;
            p = trieP[p][c];
        }
        if( nk == 1 ) color[p] = ilen + 1;
    }

    int sum = 0;
    for( int i = 1; i < k; i++ ) sum += color[i];
    return sum;
}