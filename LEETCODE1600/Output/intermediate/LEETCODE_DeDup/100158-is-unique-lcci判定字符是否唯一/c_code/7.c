#define CHARNUM 256

bool isUnique(char* astr){
    int sz, i;
    int *arr = NULL;

    sz = strlen(astr);
    if (sz <= 1) {
        return true;
    }

    arr = (int *)malloc(sizeof(int) * CHARNUM);
    memset(arr, 0, sizeof(int) * CHARNUM);

    for (i = 0; i < sz; i++) {
        arr[astr[i]]++;
        if (arr[astr[i]] > 1) {
            return false;
        }
    }

    free(arr);
    return true;
}