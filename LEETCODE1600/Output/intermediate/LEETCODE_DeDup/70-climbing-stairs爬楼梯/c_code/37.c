long int mul(int n,int m){
    long int result=1;
    for (int i=0;i<m;i++)
        result=result*(n+i+1)/(i+1);
    return result;
}//实现 (n+m)!/(n!*m!)
int climbStairs(int n){
    int kinds=1;
    int i=n-2;
    int numTwo=1;
    int numOne=i;
    while(i>0){
        if (numOne>numTwo)
            kinds=kinds+mul(numOne,numTwo);
        else
            kinds=kinds+mul(numTwo,numOne);
        //printf("%d %d %d\n",numOne,numTwo,kinds);
        i=i-2;
        numOne=i;
        numTwo++;
    }
    if (i==0)
        kinds++;
    return kinds;
}