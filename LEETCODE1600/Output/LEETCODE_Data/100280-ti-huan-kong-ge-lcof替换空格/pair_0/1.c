char output[10001] = { 0 };
char* replaceSpace(char* s) {
    int len = strlen(s);
    memset(output,0,10001);
    char* out = output;
    int index = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            strcat(out + index, "%20");
            index += 3;
        }
        else
        {
            *(out + index) = *s;
            index++;
        }
        s++;
    }
    return out;
}