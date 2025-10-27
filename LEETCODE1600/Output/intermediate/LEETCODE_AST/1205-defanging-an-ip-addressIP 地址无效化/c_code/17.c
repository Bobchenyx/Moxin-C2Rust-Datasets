char * defangIPaddr(char * address){
    int i = 0;
    int j = 0;
    int len = 0;
    char *invalidIPAddr = NULL;
    len = strlen(address);
    invalidIPAddr = (char *)malloc((len + 6 + 1) * sizeof(char));
    memset(invalidIPAddr, 0x00 , (len + 6 + 1) * sizeof(char));
    for(i = 0, j = 0; i < len,j < (len + 6 + 1); i++, j++) {
        if(address[i] != '.') {
            invalidIPAddr[j] = address[i];
        }
        else {
            invalidIPAddr[j] = '[';
            j++;
            invalidIPAddr[j] = address[i];
            j++;
            invalidIPAddr[j] = ']';
        }
    }
    return invalidIPAddr;
}