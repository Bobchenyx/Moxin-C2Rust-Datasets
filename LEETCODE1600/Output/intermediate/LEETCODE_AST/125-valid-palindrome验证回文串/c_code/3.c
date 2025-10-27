bool isPalindrome(char * s)
{
    int len = strlen(s);
    int i = 0, j = len-1;
    
    while (i < j) {
        if (isalnum(s[i]) && isalnum(s[j])) {
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            if (tolower(s[i]) == tolower(s[j]))
                ++i,--j;
        }
        if (!isalnum(s[i]))
            ++i;
        if (!isalnum(s[j]))
            --j;
    }
    return true;
}