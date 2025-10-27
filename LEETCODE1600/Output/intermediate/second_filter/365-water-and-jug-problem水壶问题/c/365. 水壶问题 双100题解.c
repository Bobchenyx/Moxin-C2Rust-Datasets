bool canMeasureWater(int x, int y, int z)
{
    if(z==0||(x+y)==z)
    {
        return true;
    }
    else
    {
        if((x+y)<z)
        {
            return false;
        }
        else
        {
            for(int i=(x>y?y:x);i>=1;i--)
            {
                if((x%i)==0&&(y%i)==0)
                {
                    return z%i==0;
                }
            }
        }
    }
    return false;
}