static const bool walk_map[9][9] = {
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
};

static void dfs(int arr[], int pos, int len, int level, int cnt[]);
int numberOfPatterns(int m, int n)
{
    int cnt[10] = {0};
    int corner[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    dfs(corner, 1, 9, n, cnt);
    int edge[9] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
    dfs(edge, 1, 9, n, cnt);
    for (int i = 1; i <= n; i++)
        cnt[i] *= 4;
    int core[9] = {4, 0, 1, 2, 3, 5, 6, 7, 8};
    dfs(core, 1, 9, n, cnt);

    int result = 0;
    for (int i = m; i <= n; i++)
        result += cnt[i];
    
    return result;
}

static inline void swap(int arr[], int l, int r)
{
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

static inline bool can_walk(int arr[], int used, int from, int to)
{
    if (walk_map[from][to])
        return true;
    int spring_board = (from + to) / 2;
    for (int i = 0; i < used; i++)
        if (arr[i] == spring_board)
            return true;
    return false;
}

static void dfs(int arr[], int pos, int len, int level, int cnt[])
{
    cnt[pos]++;
    if (pos == level)
        return;
    
    for (int i = pos; i < len; i++) {
        if (!can_walk(arr, pos, arr[pos - 1], arr[i]))
            continue;
        swap(arr, pos, i);
        dfs(arr, pos + 1, len, level, cnt);
        swap(arr, pos, i);
    }
}