bool hasGroupsSizeX(int* deck, int deckSize)
{
    int nums[10000+1]={0},Xmax=100000,dmax=0,dmin=100000;

    for(int i=0;i<deckSize;i++)
    {   
        nums[deck[i]]++;
        if(deck[i]>dmax){dmax=deck[i];}
        if(deck[i]<dmin){dmin=deck[i];}
    }

    for(int i=0;i<10001;i++)
    {
        if(nums[i]>0&&nums[i]<Xmax)
        {
            Xmax=nums[i];
        }
    }    

    if(Xmax==1)
    {
        return false;
    }

    //printf("dmin=%d dmax=%d \n",dmin,dmax);

    for(int X=2;X<=Xmax;X++)
    {
        int i;
        for(i=dmin;i<=dmax;i++)
        {
            //printf("nums[%d]=%d ",i,nums[i]);
            if(nums[i]>1&&nums[i]%X!=0)
            {
                break;
            }
        }
        if(i>dmax)
        {
            return true;
        } 
    }

    return false;
}