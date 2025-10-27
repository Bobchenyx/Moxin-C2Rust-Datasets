#define INTMAX (pow(2,31)-1)
#define INTMIN (-pow(2,31))

int reverse(int x){
    int result = 0;
    int orig = x;

    while (orig) {
        if (INTMAX/10 < result || INTMIN/10 > result) return 0;
        result = result*10;
        if ((INTMAX - (orig % 10) < result) || (INTMIN - (orig % 10) > result)) return 0;
        result += (orig % 10);
        orig /= 10;
    }

    return result;
}