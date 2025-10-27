char* replaceSpaces(char* S, int length){
    char *ans = (char *)malloc(sizeof(char) * (3 * length + 1));
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (S[i] == ' ') {
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        } else ans[j++] = S[i];
    }
    ans[j] = '\0';
    return ans;
}