double tmp[5000][5000];

double dp(int a, int b)
{
    double res = 0;

    if (a <= 0) {
        if (b > 0)
            return 1;
        else
            return 0.5;
    } else if (b <= 0) {
        return 0;
    }
    if (tmp[a][b] > 0)
        return tmp[a][b];

    res = (dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3)) / 4;
    tmp[a][b] = res;
    return res;
}

double soupServings(int N){
    if (N >= 4850)
        return 1;

    N = N / 25 + ((N % 25) > 0 ? 1 : 0);
    return dp(N, N);
}