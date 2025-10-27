class Solution {
public:
    string compressString(string S) {
        char str[50050];
        int index = 0;
        bool sign;
        int shengyu;

        for(int i = 0 ; i < S.length(); i++)
        {
            sign = true;
            shengyu = i;

            for(int j = i + 1 ; j < S.length(); j++)
            {
                if(S[i] != S[j])
                {
                   str[index++] = S[i];
                   int d[5];
                   int pre = 0;
                   int len = j - i;
                    while(len != 0)
                    {
                        d[pre++] = '0' + len % 10;
                        len = len / 10;
                    }

                    while(pre > 0)
                        str[index++] = d[--pre];

                    i = j - 1;
                    sign = false;
                    break;
                }
            }

            if(sign != false)
                break;

            if(index > S.length())
                return S;
        }

        if(sign)
        {
            int len = S.length() - shengyu;
            str[index++]  = S[shengyu];
            int d[5];
            int pre = 0;
            while(len != 0)
            {
                d[pre++] = '0' + len % 10;
                len = len / 10;
            }

            while(pre > 0)
                str[index++] = d[--pre];

            if(index >= S.length())
                return S;

            str[index] = '\0';
        }
        else
            str[index] = '\0';
        return str;
    }
};