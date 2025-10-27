char * addBinary(char * a, char * b){
    int alen = strlen(a);
    int blen = strlen(b);
    int length = (alen > blen) ? alen + 2 : blen + 2;
    char* c = (char*)malloc(length*(sizeof(char)));
    memset(c, '0', length);
    c[length - 1] = '\0';
    for(length -= 2; length > 0; length--){
        int an = (alen > 0) ? a[--alen] - '0' : 0;
        int bn = (blen > 0) ? b[--blen] - '0' : 0;
        c[length] += (an + bn);
        if(c[length] == '2'){
            c[length] = '0';
            c[length - 1] ++;
        }
        else if(c[length] == '3'){
            c[length] = '1';
            c[length - 1] ++;
        }
    }
    if(c[0] == '0')
        c++;
    return c;
}