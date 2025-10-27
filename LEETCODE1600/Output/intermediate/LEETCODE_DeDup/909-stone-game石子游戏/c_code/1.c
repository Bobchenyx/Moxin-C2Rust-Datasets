bool stone(int* piles, int i, int j, int val, bool alex) {
    int vl, vr;
    //terminater
    if (i == j) {
        return (((alex) ? (val + piles[i]):(val - piles[i])) > 0);
    }

    //process
    vl = (alex) ? (val + piles[i]):(val - piles[i]);
    vr = (alex) ? (val + piles[j]):(val - piles[j]);

    //recursion
    return stone(piles, i+1, j, vl, !alex) || stone(piles, i, j+1, vr, !alex);
}

bool stoneGame(int* piles, int pilesSize){
    return stone(piles, 0, pilesSize-1, 0, true);
}