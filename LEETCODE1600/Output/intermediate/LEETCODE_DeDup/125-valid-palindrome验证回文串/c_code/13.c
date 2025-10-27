bool isPalindrome(char * s)
{
    int i=0;
    int len=strlen(s);
    int j=len-1;
    int count;
    
    for(count=0;count<len;count++)
    {
        if(s[count]<='Z' && s[count]>='A')
        {
            s[count]+='a'-'A';
        }
    }
    
    
    for(;i<len;i++)
    {
        if((s[i]>='a' && s[i]=<'z') || (s[i]>='0' && s[i]=<'9'))
        {
            while(j>-1)
            {
                if((s[j]>='a' && s[j]=<'z') || (s[j]>='0' && s[j]=<'9'))
                {
                    
                    if(s[i]==s[j])
                    {
                        j--;
                        break;
                    }else
                    {
                        return false;
                    }
                }else
                {
                    j--;
                }
            }
        }
    }
    return true;
}