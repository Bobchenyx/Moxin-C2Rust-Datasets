/* 统计各个数字出现的次数，求其最大公约数，使用辗转相除法 */
#define DifCardNums 1000
int difCardCount[DifCardNums];
int gcd(int a, int b) {
    if(a<0 || b<0) {
        return 0;
    }
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    while(b!=0) {
        int k = a%b;
        a = b;
        b = k;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if(deck == NULL || deckSize<1) {
        return false;
    }
    memset(difCardCount, 0, sizeof(int) * DifCardNums);
    for (int i =0; i< deckSize; i++) {
        difCardCount[deck[i]]+=1;
    }
    int gcdnum=-1;
    for (int i =0; i< DifCardNums; i++) {
        if(difCardCount[i] != 0 ) {
            if(gcdnum==-1) {
                gcdnum = difCardCount[i];
            } else {
                gcdnum = gcd(difCardCount[i], gcdnum);
            }
        }
    }
    if (gcdnum>= 2) {
        return true;
    }
    return false;
}