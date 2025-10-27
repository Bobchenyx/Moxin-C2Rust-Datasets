int reverse(int x){
    int recur(int,int*,int*);
    int overflow = 0;                
    if(x == INT_MIN){                //判断最小负值      
        return 0;
    }                       
    if(abs(x) > 1000000000 && abs(x % 10) > 2){ return 0;}  //判断值是否为10位数且个位大于2（这种情况无法在递归中检查）
    int a = 0;
    int res = recur(x,&a,&overflow);          
    return res;
}
int recur(int val,int *p,int *overflow){    //指针参数p求每个十进制位翻转后对应的位置，overflow为溢出标志
    if(abs(val) < 10){               
        (*p)++;
        return val;
    }   
    int sum = recur(val/10,p,overflow);
    if(*overflow){ return 0; }   
    int num = val % 10 * pow(10,(*p));
    (*p)++;
    *overflow =(num > 0 && INT_MAX - num < sum) || (num < 0 && INT_MIN - num > sum ) ? 1 : 0;   
    return (*overflow) ? 0 : num + sum;
}