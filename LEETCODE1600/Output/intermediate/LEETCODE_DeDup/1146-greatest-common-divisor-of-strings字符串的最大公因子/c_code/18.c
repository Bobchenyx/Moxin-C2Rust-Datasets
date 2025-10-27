#define MAX_LENGTH  2001

int gcd(int x, int y){
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd(x - y, y);
}

char * gcdOfStrings(char * str1, char * str2){
    if (str1 == NULL || str2 == NULL) {
        return "";
    }

    char s1[MAX_LENGTH] = {0};
    for (int i = 0; i < strlen(str1); i++){
        s1[i] = str1[i];
    }
    strcat(s1, str2);

    char s2[MAX_LENGTH] = {0};
    for (int i = 0; i < strlen(str2); i++){
        s2[i] = str2[i];
    }
    strcat(s2, str1);

    char *res = (char *)malloc(sizeof(char) * MAX_LENGTH);
    memset(res, 0, sizeof(char) * MAX_LENGTH);

    if (strcmp(s1, s2)) {
        return "";
    }

    int size = gcd(strlen(str1), strlen(str2));
    memcpy(res, str1, sizeof(char) * size);

    return res;
}