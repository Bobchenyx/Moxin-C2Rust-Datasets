bool canThreePartsEqualSum(int* A, int ASize)
{
    int sum=0;
    int part=0;
    int x=0;
    int count=0;
    for(int i=1;i<=ASize;i++)
    {
        sum+=A[i-1];
    }
   
    if(sum%3!=0)
    {
        return 0;
    }
    else
    {
        part=sum/3;
      
        for(int i=1;i<=ASize;i++)
        {
            x+=A[i-1];
            if(x!=part)
            {
                continue;
            }else
            {
                x=0;
                count++;
            }
        }
    }
    if(count==3 && x==0)
    {
        return 1;
    }
    else if(count>=3 && x==0 && part==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}