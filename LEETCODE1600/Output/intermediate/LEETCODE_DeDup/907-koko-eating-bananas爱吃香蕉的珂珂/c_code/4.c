int minEatingSpeed(int* piles, int pilesSize, int H){
    int maxSpeed = 0;
    long long totalBanana = 0;
    int tmp = 0;
    for (int i = 0; i < pilesSize; i++) {
        maxSpeed = maxSpeed > piles[i] ? maxSpeed : piles[i];
        totalBanana += piles[i];
    }
    
    for (int k = totalBanana/H + 1; k < maxSpeed; k++) {
        tmp = 0;
        for (int j = 0; j < pilesSize; j++) {
            tmp += (piles[j] / k) + (piles[j] % k > 0 ? 1 : 0);
        }
        if (tmp <= H) {
            return k;
        }
    }
    return maxSpeed;
}