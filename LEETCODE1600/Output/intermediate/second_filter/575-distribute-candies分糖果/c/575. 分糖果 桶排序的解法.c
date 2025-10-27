int distributeCandies(int* candies, int candiesSize)
{
    int ret=0,candies_count[200000+1]={0};

    for(int i=0;i<candiesSize;i++)
    {
        if(candies_count[candies[i]+100000]==0)
        {
            ret+=1;
        }
        candies_count[candies[i]+100000]+=1;
    }

    if(candiesSize/2>ret)
    {
        return ret;
    }
    
    return candiesSize/2;
}