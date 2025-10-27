void func(int* Nums)
{
    int sum=0;
    while(*Nums)
    {
        sum+=(*Nums%10)*(*Nums%10);
        *Nums=*Nums/10;
    }
    *Nums=sum;
}

bool isHappy(int n){
    int slow=n,fast=n;
    do
    {
        func(&slow);
        func(&fast);
        func(&fast);
    }
    while(fast!=slow);
    return slow==1;
}