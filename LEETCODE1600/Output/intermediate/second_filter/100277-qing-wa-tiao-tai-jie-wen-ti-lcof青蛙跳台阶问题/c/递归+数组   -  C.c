#define MAX_VALUE 1010
int arr[1010]= {-1};
int func(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (arr[n] != -1) {
        return arr[n];
    }
    arr[n] = (func(n - 1) + func(n - 2)) % 1000000007;
    return arr[n];
}

int numWays(int n){
    int value;
    int i;

    for (i = 0; i < MAX_VALUE; i++) {
        arr[i] = -1;
    }
    value = func(n);
    return value;
}