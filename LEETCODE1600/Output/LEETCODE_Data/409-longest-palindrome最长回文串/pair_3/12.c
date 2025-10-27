int longestPalindrome(char * s){
    int len = strlen(s);
    int i = 0;
    int counts[200] = {0};
    int ret = 0;
    int x = 0;
    int first_odd = 0;
    //printf("A = %d, Z = %d, a =%d, z = %d\n",'A', 'Z', 'a', 'z');
    for(i = 0 ; i < len; i++) {
        x = (int)(s[i] - 'A');
        //printf("x = %d, s[%d] = %c\n",x, i, s[i]);
        counts[x] = counts[x] + 1;
    }

    for(i = 0; i < 200; i++) {
        if(counts[i] % 2 == 0) {
            ret = ret + counts[i];
        }
        else {
            if(counts[i] > 1) {
                if(first_odd == 0) {
                    ret = ret + 1;
                    first_odd = 1;
                }
                ret = ret + counts[i] - 1;
            }
            else {
                if(first_odd == 0) {
                    ret = ret + 1;
                    first_odd = 1;
                }                
                continue;
            }
        }
    }
    return ret;

}