/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int *res = NULL;
    res = (int *)malloc(sizeof(int) * (n + 2));
    memset(res, 0, (sizeof(int) * (n + 2)));

    int p[n + 2];    
    memset(p, 0, (sizeof(int) * (n + 2)));
    *returnSize = n;
    for (int i = 0; i < bookingsSize; i++) {
        p[bookings[i][0]] += bookings[i][2];
        p[bookings[i][1] + 1] -= bookings[i][2];
    }
    
    for (int i = 1; i <= n; i++) {
        res[i] = res[i - 1] + p[i];
    }
    return (res + 1);
}