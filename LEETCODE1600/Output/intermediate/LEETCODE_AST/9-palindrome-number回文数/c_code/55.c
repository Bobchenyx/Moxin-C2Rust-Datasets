bool isPalindrome(int x){
    char arr[512];
    char *pstart, *pend;
    int len;

    len = sprintf(arr, "%d", x);
    pstart = arr;
    pend = arr + len - 1;

    while (pstart < pend)
    {
        if (*pstart != *pend) return false;
        pstart++;
        pend--;
    }
    return true;
}