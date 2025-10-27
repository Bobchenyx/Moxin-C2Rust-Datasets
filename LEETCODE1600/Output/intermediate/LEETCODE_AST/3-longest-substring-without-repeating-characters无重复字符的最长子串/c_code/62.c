int lengthOfLongestSubstring(char * s){

    int length = strlen(s);
    if(length<=1) return length;

    int map[128]={0};

    int i=0,j=0;
    int large=0;
    while(i<length&&j<length)
    {
        int k =s[j];
        map[k]++;    // s[j] add map;
        if(map[k]==1)    // new different
        {
            ++j;
            if((j-i)>large) large=j-i;
        }
        else   // add a same
        {
            map[k]--;
            map[s[i++]]--;
        }
    }

    return large;

}