//递归，时间超出
int coinChange(int* coins, int coinsSize, int amount){
    int i;
    for(i=0;i<coinsSize;i++)
    if(amount==coins[i])
    {return 1;
   }
    if(amount<coins[0])//小于最小的
    {
        return -1;
    }int coinChange(int* coins, int coinsSize, int amount){
    int i;
    for(i=0;i<coinsSize;i++)
    if(amount==coins[i])
    {return 1;
   }
    if(amount<coins[0])//小于最小的
    {
        return -1;
    }
    else
    {
        int count=amount+1;
        int number;
        for(i=coinsSize-1;i>=0;i--)
        {
            number=coinChange(coins,coinsSize,(amount-coins[i]));
            if(number!=-1)
            count=(count<number?count:number);
        }
        if(count==amount+1)//没有一种方法能股通过
        return -1;
        return count+1;
    }
    return -1;
}

    else
    {
        int count=amount+1;
        int number;
        for(i=coinsSize-1;i>=0;i--)
        {
            number=coinChange(coins,coinsSize,(amount-coins[i]));
            if(number!=-1)
            count=(count<number?count:number);
        }
        if(count==amount+1)//没有一种方法能股通过
        return -1;
        return count+1;
    }
    return -1;
}