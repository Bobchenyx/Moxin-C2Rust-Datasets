int UglyNum(int num)
{
    if (num == 1) {
        return 1;
    }
    if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) {
        return 0;
    }
    int ret = 0;
    if (num % 2 == 0) {
        ret = UglyNum(num / 2);
    } else if (num % 3 == 0) {
        ret = UglyNum(num / 3);
    } else if (num % 5 == 0) {
        ret = UglyNum(num / 5);
    }
    return ret;
}
bool isUgly(int num) {
    if (num <= 0) {
        return false;
    }
    int ret;
    ret = UglyNum(num);
    return ret > 0 ? true : false;
}