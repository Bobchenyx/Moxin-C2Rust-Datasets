int lengthOfLongestSubstring(char * s){
    char *h = s;
    char *t = NULL;
    int Len = 0;
    int tmp = 0;
    int index[128] = {0};

    if (strlen(s) == 0)
        return 0;

    if (strlen(s) == 1)
        return 1;

    for (int i = 0; i < strlen(s) - 1; i++) {   
       index[*h] = 1; 
       t = h + 1;
       
       while (index[*t] == 0) {
           index[*t] = 1;
           t++;
           if (*t == '\0') 
                break;
       }

       tmp = t - h;
       if (tmp > Len)
            Len = tmp;
             
       h++;
       memset(index, 0, 4*128);                                  
    }  

    return Len;                                                                                                    
}