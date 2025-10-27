//斐波那契数列
int climbStairs(int n){
    int a=1,b=1,temp=0;
    while(--n){
        temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}