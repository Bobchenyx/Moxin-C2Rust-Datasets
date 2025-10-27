int Max(int a, int b) { return a > b ? a : b; }
int longestMountain(int *A, int ASize)
{
    int i, l, r, max = 0;
    for (i = 1; i < ASize - 1; i++)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            for (l = i; l - 1 >= 0 && A[l - 1] < A[l]; l--);
            for (r = i; r + 1 < ASize && A[r] > A[r + 1]; r++);
            max = Max(r - l + 1, max);
        }
    }
    return max;
}