int getMaxDiv(int a, int b)   
{
    while(a != b)    
    {   
        if(a > b)    
            a = a - b;    
        if(a < b)    
            b = b - a;    
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    int  i, j = 0;
    int  sum = 1;
    int  num[10000] = {0};
    int  num1[10000] = {0};
    int  maxDiv = 0;
    int  temp = 0;
    int  flag = 0;

    if (deckSize < 2)
    {
        return 0;
    }

    for (i = 0; i < deckSize; i++)
    {
        num[deck[i]]++;
    }

    for (i = 0; i < 10000; i++)
    {
        if (num[i] != 0)
            num1[j++] = num[i];
    }    

    for (i = 0; i < j-1; i++)
    {
        maxDiv = getMaxDiv(num1[i], num1[i+1]);       
        if (maxDiv < 2) 
            return 0;
    }

    return 1;
}