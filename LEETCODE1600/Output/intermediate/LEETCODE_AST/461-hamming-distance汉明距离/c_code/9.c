int hammingDistance(int x, int y){
    int c,d,e,temp,res,count;
    count=0;
    c=x&y;
    d=x|y;
    e=c^d;
    temp=e;
    while(1)
    {
        if((temp/2)!=0)
        {
            res=temp%2;
            temp=temp/2;
            if(res==1)
            {
                count++;
            }
        }
        else
        {
            if(temp!=0)
            {
                count++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}