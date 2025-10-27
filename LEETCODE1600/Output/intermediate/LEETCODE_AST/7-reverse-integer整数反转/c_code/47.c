#include <math.h>
int reverse(int x){
    const int INTMAX= pow(2,31);

    int pop,rev = 0;

    //使用计算，一步一步进行栈活动
    while(x!=0){
        //pop
        pop = x%10;
        x=x/10;//剩下数字
        //push in stack
        if(rev>INTMAX/10 || (rev == INTMAX/10 && pop>7)) return 0;
        if(rev<(-INTMAX/10) || (rev == (-INTMAX/10) && pop<-7)) return 0;
        rev = rev*10 + pop;
    }
    return rev;
}