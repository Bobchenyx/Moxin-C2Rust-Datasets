int myAtoi(char * str){
    long long int num = 0;

    sscanf(str, "%lld", &num);
    if (num > 2147483647) return 2147483647;
    if (num < -2147483648) return -2147483648;
    return (int)num;
}