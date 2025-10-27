int f(int n, int m)
{
    if (n == 1) {
        return 0;
    }
    int nextIterIndex = f(n - 1, m);
    int nextIterStart = m % n;
    return (nextIterStart + nextIterIndex) % n;
}

int lastRemaining(int n, int m) {
    return f(n, m);
}