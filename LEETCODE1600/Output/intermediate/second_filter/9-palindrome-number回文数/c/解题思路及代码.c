#define MAX_INT_LEN  12

bool isPalindrome(int x) {
    char str[MAX_INT_LEN];
    int i, j;
    int flag;

    sprintf(str, "%d", x);

    if (strlen(str) < 2) {
        return 1;
    }

    i = 0;
    j = strlen(str) - 1;
    flag = 0;
    while (i<j) {
        if (str[i] == str[j]) {
            i++;
            j--;
            flag = 1;
        }
        else {
            flag = 0;
            break;
        }
    }

    return flag;
}