int climbStairsB(int, int*);

int climbStairs(int n){
    int* mem = (int*)calloc(n, sizeof(int));
    int cnt = climbStairsB(n, mem);
    free(mem);
    return cnt;
}

int climbStairsB(int n, int* mem){
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (mem[n - 1] > 0) return mem[n - 1];
    mem[n - 1] = climbStairsB(n - 1, mem) + climbStairsB(n - 2, mem);
    return mem[n - 1];
}