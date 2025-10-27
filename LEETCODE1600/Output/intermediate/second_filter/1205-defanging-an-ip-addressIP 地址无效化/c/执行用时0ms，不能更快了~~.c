char* defangIPaddr(char* address) {
    int len = strlen(address);
    char* res = (char*)malloc(len + 6 + 1);
    char* p = res;
    memset(p, 0, len + 6);
    while (*address != '\0') {
        if (*address == '.') {
            *p++ = '[';
            *p++ = '.';
            *p++ = ']';
        }
        else {
            *p++ = *address;
        }
        address++;
    }
    *p = '\0';
    return res;
};