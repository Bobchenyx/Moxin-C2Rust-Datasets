int subtractProductAndSum(int n){
    int remainder,quotient,sum,product,result;
    sum=0;
    product=1;
    quotient=n;
    result=0;
    do
    {
        remainder=quotient%10;
        quotient=quotient/10;
        sum=remainder+sum;
        product=product*remainder;
    }
    while (quotient!=0);
    result=product-sum;
    return result;
}