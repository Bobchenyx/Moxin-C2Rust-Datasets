int firstUniqChar(char * s) {
    int i=0, ret=-1;
    int arr[128] = {0};
    while (s[i]!='\0') {
        arr[s[i]]++;
        i++;
    }
    i=0;
    while (s[i]!='\0') {
        if (arr[s[i]]==1) {
            ret=i;
            break;
        }
        i++;
    }
    return ret;
}