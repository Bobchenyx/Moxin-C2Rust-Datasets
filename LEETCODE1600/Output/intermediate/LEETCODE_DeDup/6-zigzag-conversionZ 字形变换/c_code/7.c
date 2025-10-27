char * convert(char * s, int numRows){
    int i;
    int j;
    int step;
    int tag;
    int m = 0;
    int len = strlen(s);

    if (numRows == 0 || numRows == 1) {
        return s;
    }

    char *str = (char*)malloc(sizeof(char) * (len + 1));

    step = 2 * numRows - 2;

    for (i = 0; i < numRows; i++) {
        j = i;
        tag = 0;
        while (j < len) {
            str[m++] = *(s + j);
            if (i == 0 || i == numRows - 1) {
                j = j + step;
            } else {
                if (tag == 0) {
                    j = j + step - 2 * i;
                    tag = 1;
                } else {
                    j = j + 2 * i;
                    tag = 0;
                }
            }

        }
    }
    str[len] = '\0';
    return str;
}