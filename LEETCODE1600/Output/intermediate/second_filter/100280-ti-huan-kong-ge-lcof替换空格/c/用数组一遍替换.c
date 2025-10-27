char* replaceSpace(char* s){
    char* c = s;
    char *s1 = (char*)malloc(10000*sizeof(char));
    int index = 0;
    while(*c) {
        if(*c == ' ') {
            s1[index++] = '%';
            s1[index++] = '2';
            s1[index++] = '0';
        } else {
            s1[index++] = *c;
        }
        c++;
    }
    s1[index] = NULL;
    return s1;
}