char * gcdOfStrings(char * str1, char * str2){
    if (!str1 || !str2) return "";

    int pos1=0;
    int pos2=0;

    while (1) {
        int len1=strlen(str1+pos1);
        int len2=strlen(str2+pos2);

        if (!strcmp(str1+pos1, str2+pos2)) {
            return str1+pos1;
        }

        if (len1 == len2)  {
            return "";
        }

        if (len1 > len2) {
            pos1 += strlen(str2+pos2);
        } else {
            pos2 += strlen(str1+pos1);
        }
    }
    return "";    
}