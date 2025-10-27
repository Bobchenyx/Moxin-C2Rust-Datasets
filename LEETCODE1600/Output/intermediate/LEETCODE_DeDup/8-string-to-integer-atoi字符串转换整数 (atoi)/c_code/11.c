#include <ctype.h>

int myAtoi(char * str){
    long int ans = 0;
    char sign = 1;
    int Tmin = -2147483648;
    int Tmax = 2147483647;
    char c;
    while ((c = *str) == ' ') str++;
    if (*str == '-'){
        sign = -1;
        str++;
    } 
    if (*str == '+' && sign == 1) str++;
    while (isdigit(c = *str++)){
        ans = 10 * ans + (c - '0');
        if (ans > Tmax) return (sign == 1)? Tmax : Tmin; // Tmin 的绝对值 比 Tmax 大一的问题 这里应该没问题
    }
    return sign * ans;
}