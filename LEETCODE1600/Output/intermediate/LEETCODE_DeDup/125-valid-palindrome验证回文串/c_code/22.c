void alphToLower(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ('A' <= s[i] <= 'Z')
            s[i] = tolower(s[i]);
    }
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    // set a front pointer which point at the beginning of the string
    char* pf = s;
    // set a tail pointer
    char* pt = s + len - 1;
    bool ret = true;
    alphToLower(s);
    puts(s);
    while (pf < pt)
    {
        if (('a' <= *pf && *pf <= 'z') || ('0' <= *pf && *pf <= '9'))
        {
            if (('a' <= *pt && *pt <= 'z') || ('0' <= *pt && *pt <= '9'))
            {
                if (*pf == *pt)
                {
                    pf++;
                    pt--;
                    continue;
                }
                else
                {
                    ret = false;
                    break;
                }
            }
            else
            {
                pt--;
                continue;
            }
        }
        else
            pf++;
    }
    return ret;
}