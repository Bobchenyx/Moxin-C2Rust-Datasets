int numJewelsInStones(char * J, char * S){
    int i= 0;
    int j = 0;
    int lenJ = 0;
    int lenS = 0;
    int count = 0;
    if(J == NULL || S == NULL) {
        return 0;
    }
    lenJ = strlen(J);
    lenS = strlen(S);

    for(i = 0; i < lenS; i++) {
        for(j = 0; j < lenJ; j++) {
            if(S[i] == J[j]) {
                count++;
            }
        }
    }
    return count;
}