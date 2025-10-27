#if 1

// Reverse the string
int string_reverse(char *str, int len)
{
    char tmp = 0;
    int pos = 0;

    if ((!str) || (!len)) {
        return -1;
    }

    len = len - 1;
    while (pos < (len >> 1)) {
        tmp = *(str + pos);
        *(str + pos) = *(str + (len - pos) - 1);
        *(str + (len - pos) - 1) = tmp;
        pos++;
    }

    return 0;
}

char * addBinary(char * a, char * b)
{
    char *pOut = NULL;
    char *pa = NULL;
    char *pb = NULL;

    int pos = 0;
    int alen = 0;
    int blen = 0;
    int len = 0;
    int cnt = 0;
    char plus = 0;
    char flag = 0;
    char aChar = 0;
    char bChar = 0;
    char tmp = 0;
    int ret = -1;

    if ((!a) || (!b)) {
        printf("param is null!\n");
        return NULL;
    }
    pa = a;
    pb = b;

    alen = strlen(a);
    blen = strlen(b);
    len = alen > blen ? alen : blen;

    pOut = (char *)malloc(sizeof(char) * (len + 2));
    if (!pOut) {
        printf("malloc failed!\n");
        return NULL;
    }

    while ((alen > 0) || (blen > 0) || (flag > 0)) {
        if (alen > 0) {
            aChar = *(pa + alen - 1) - '0';
        } else {
            aChar = 0;
        }
        if (blen > 0) {
            bChar = *(pb + blen - 1) - '0';
        } else {
            bChar = 0;
        }

        plus = aChar + bChar + flag;
        flag = plus / 2;
        plus = plus % 2;

        *(pOut + pos) = plus + '0';
        pos++;
        if (alen > 0) {
            alen--;
        }
        if (blen > 0) {
            blen--;
        }
    }
    *(pOut+pos) = '\0';

    ret = string_reverse(pOut, strlen(pOut) + 1);
    if (ret) {
        return NULL;
    }

    return pOut;
}

#else

// 第二种方法，适用于数据长度在32位以内的整数加法

int get_data_bit(int data)
{
    int i = 0;

    if (!data)
        return 1;

    while (data) {
        data = data >> 1;
        i++;
    }

    return i;
}

int data_to_string(int data, char *str, int len)
{
    int pos = len - 1;

    if (!data) {
        *str = '0';
    }
    *(str + len) = '\0';    
    while ((data) && (pos >= 0)) {
        *(str + pos) = data % 2 + '0';
        data = data / 2;
        pos--;
    }

    return 0;
}

char * addBinary(char * a, char * b)
{
    unsigned long aData = 0;
    unsigned long bData = 0;
    unsigned long total = 0;
    int len = 0;
    int ret = -1;
    char *pOut = NULL;

    if ((!a) || (!b)) {
        printf("param is null!\n");
        return NULL;
    }

    aData = strtol(a, NULL, 2);
    bData = strtol(b, NULL, 2);
    total = aData + bData;

    len = get_data_bit(total);

    pOut = (char *)malloc(sizeof(char) * (len + 1));
    if (!pOut) {
        printf("malloc failed!\n");
        return NULL;
    }

    ret = data_to_string(total, pOut, len);
    if (ret) {
        printf("data_to_string error, ret: %d\n", ret);
        return NULL;
    }

    return pOut;
}

#endif