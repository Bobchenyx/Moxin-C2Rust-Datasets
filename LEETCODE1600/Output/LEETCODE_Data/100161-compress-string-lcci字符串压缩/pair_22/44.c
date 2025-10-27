char* compressString(char* S)
{
    int len = strlen(S);
    int i = 0;
    int j = 0;
    int k = 0;
    if(len == 0 || len == 1)
    {
        return S;
    }
    char* new_s = (char*)malloc(len * sizeof(char));

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(S[i] != S[j])
            {
                break;
            }
        }
        if(k < len-2)
        {
            new_s[k++] = S[i];
            //下面把统计的数字转换为字符串
            int tmp = j - i;
            int intTostr[6] = {0};
            int t = 0;
            while(tmp != 0)
            {
                intTostr[t++] = tmp % 10 + '0';
                tmp /= 10;
            }
            while(t > 0)
            {
                new_s[k++] = intTostr[--t];
            }

            i = j-1;
        }
        else
        {
            return S;
        }
    }
    new_s[k] = '\0';
    return new_s;
}