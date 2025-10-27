//能否吃完
int possible(int* piles,int pilesSize, int speed, int hour)
{
    int time = 0;
    for (int i = 0; i<pilesSize; i++) {
        time = time + (*(piles + i) - 1)/speed + 1;
    }
    if (time > hour) {
        return 0;
    }
    return 1;
}

int minEatingSpeed(int* piles, int pilesSize, int H){
    int low = 1;
    int high = (int)pow(10,9);
    int mid = 0;
    if ((NULL == piles) || (0 == pilesSize) || (0 == H)) {
        return 0;
    }
    while (low < high) {
        mid = low + (high - low)/2;
        if (!possible(piles, pilesSize, mid,H)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    //当low >=high 并且low来自某一个吃不完的mid,此mid+1一定为这个临界点。
    return low;
}