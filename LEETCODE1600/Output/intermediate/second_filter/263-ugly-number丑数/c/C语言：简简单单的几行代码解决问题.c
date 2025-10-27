bool isUgly(int num){
    if (num < 1) return false;
    return judge(num);
}
int judge(int num) {
    int ret = 0;
    if (num == 1) return 1;
    if (num % 2 == 0)         ret = judge(num / 2);
    if (!ret && num % 3 == 0) ret = judge(num / 3);
    if (!ret && num % 5 == 0) ret = judge(num / 5);

    return ret;
}