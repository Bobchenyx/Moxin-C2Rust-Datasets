int majorityElement(int* nums, int numsSize)
{
    int ret_value,count,min_value,min_idx;
    int *p,*q,plen,qlen;

    p=(int *)malloc(sizeof(int)*numsSize);
    plen=0;
    q=nums;
    qlen=numsSize;
    
    while(qlen>0)
    {   
        ret_value=q[0];
        count=0;
        plen=0;
        for(int i=1;i<qlen;i++)
        {
            if(q[i]==ret_value)
            {
                count+=1;
                if(count>=(qlen/2))
                {
                    return ret_value;
                }
            }
            else
            {
                p[plen++]=q[i];
            }
        }
        if(q==nums)
        {
            q=p;
            p=nums;
        }
        else
        {
            p=q;
            q=nums;
        }
        qlen=plen;
    }

    return ret_value;
}