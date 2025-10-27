#include <Math.h>
int maximum69Number (int num){
    int count = 0, th = 0;          // count 记录除了多少次，th记录最大的6在第几位
    int re = num;
    while(re){
        count++;
        if(re%10==6)
           th = count;
        re /= 10;
    }
    return num+3*pow(10,th-1);
}