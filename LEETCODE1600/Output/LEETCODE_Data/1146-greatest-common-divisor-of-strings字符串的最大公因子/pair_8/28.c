char * gcdOfStrings(char * str1, char * str2){
    char *lger = strlen(str1) > strlen(str2) ? str1 : str2;
    char *sher = strlen(str1) > strlen(str2) ? str2 : str1;

    if (strcmp(lger, sher) == 0) {
        return sher;
    }

    if (strncmp(lger, sher, strlen(sher)) != 0) {
        return "";
    } 

    return gcdOfStrings(lger + strlen(sher), sher);
}