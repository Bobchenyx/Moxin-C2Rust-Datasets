char * longestPalindrome(char * s){
    if(s == NULL)
    {
        return NULL;
    }

    if(strlen(s) == 1)
    {
        return s;
    }

    int len = strlen(s);
    int str_len = 2*len + 3;
    char mana[str_len];
    /*注意此处radius是int类型*/
    int radius[str_len];//表示以 i 为中心的最长回文的半径

    memset(mana,0,sizeof(mana));
    memset(radius,0,sizeof(radius));

    mana[0] = '$';
    mana[1] = '#';
    int j = 2;

    for(int i = 0;i < len;i++)
    {
        mana[j++] = s[i];
        mana[j++] = '#';
    }
    mana[j] = '\0';

    int manaSize = j;
    //printf("manaSize = %d\n",manaSize);
    int id = 0;//centej
    int mx = 0;//以i为中心的回文子串的最右端
    int maxLen = 0;
    int start = 0;
    int i;
    for(i = 1;i < manaSize;i++)
    {
        if(i < mx)//i center does not exceed the right end boundary of MX
        {
            radius[i] = (mx-i)<radius[2*id-i]?(mx-i):radius[2*id-i];
        }
        else
        {
            radius[i] = 1;//once the boundary is exceeded, start counting again
        }

        /*expand from the center to the outside, and 
          gradually expand the range of palindrome 
          substring*/
        while(mana[i-radius[i]] == mana[i+radius[i]])
        {

            radius[i]++;
        }

        /*if the rightmost endpoint of the new calculation 
          is greater than mx,update id and mx */
        //printf("before i = %d id = %d mx = %d maxLen = %d radius[%d]= %d\n",i,id,mx,maxLen,i,radius[i]);
        if(radius[i] + i > mx)
        {
            id = i;
            mx = radius[i] + i;
            //printf("id = %d mx = %d\n",id,mx);
        }

        /*calculate the index value that meets the condition*/
        if(radius[i] - 1 > maxLen)
        {
            start = (i - radius[i])/2;
            maxLen = radius[i] - 1;
        }
    }


    char *res = (char*)malloc(sizeof(char)*(maxLen+1));
    for(int i = start,k = 0;i <start+maxLen;i++,k++)
    {
        res[k] = s[i];
    }
    res[maxLen] = '\0';

    return res;

}