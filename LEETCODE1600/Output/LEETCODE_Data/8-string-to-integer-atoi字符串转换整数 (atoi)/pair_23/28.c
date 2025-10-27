#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

#define IS_NUM(c)           ((c) >= '0' && (c) <= '9')

//【算法思路】字符串状态机。
int myAtoi(char * str){
    if(str == NULL || strlen(str) == 0) {
        return 0;
    }

    int slen = strlen(str);

    int state = 0;

    long long num = 0;
    int sym = 1;

    for(int i = 0; i < slen; i++) {
        if(state == 0) {
            if(str[i] == ' ') {
                continue;
            } else if(str[i] == '-' || str[i] == '+'){
                sym = str[i] == '-'? -1 : 1;
                state = 1;
            } else if(IS_NUM(str[i])) {
                num = str[i] - '0';
                state = 2;
            } else {
                break;
            }
        } else if(state == 1) {
            if(!IS_NUM(str[i])) {
                break;
            } else {
                num = str[i] - '0';
                state = 2;
            }
        } else {
            if(IS_NUM(str[i])) {
                num = num * 10 + str[i] - '0';

                if(sym == 1 && num >= INT_MAX) {
                    num = INT_MAX;
                    break;
                } else if(sym == -1 && num >= (long long)INT_MAX + 1) {
                    num = (long long)INT_MAX + 1;
                    break;
                }
            } else {
                break;
            }
        }
    }

    return (int)(sym * num);
}