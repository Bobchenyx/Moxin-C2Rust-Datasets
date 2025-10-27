char * convert(char * s, int numRows){
    int len = strlen(s);
    if (len < 1) {
        return "";
    }
    if (len <= numRows || len < 3 || numRows == 1) {
        return s;
    }
    int m = 2*numRows - 2;
    char *buf = (char*)malloc(len+1);
    memset(buf,'\0',len+1);
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        int n = 0;
        int flag = 0;
        while (1) {
            n = m*(flag++);
            if (n+i > len - 1)
                break;
            if (i == 0) {
                buf[k++] = s[n];
            }else if (i == numRows-1) {
                buf[k++] = s[n+i];
            }else {
                buf[k++] = s[n+i];
                if (n+m-i > 0 && n+m-i < len)
                    buf[k++] = s[n+m-i];
            }
        }
    }
    return buf;
}