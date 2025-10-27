int g_walkCnt;
int g_visited[MAX_SIZE][MAX_SIZE];

void Walk(int x, int y, int m, int n, int k){
    if (x >= 0 && y >= 0 && x < m && y < n && ((GetSum(x) + GetSum(y)) <= k) && (!g_visited[x][y])) {
        Node node = {x, y};
        EnQueue(&node);
        g_visited[x][y] = 1;
        g_walkCnt++;
    }
}

int Bfs(int m, int n, int k){
    Node *node = NULL;
    memset(g_visited, 0, sizeof(g_visited));
    /* 原点必然可达 */
    g_walkCnt = 1;
    g_visited[0][0] = 1;
    while (!IsEmpty()){
        node = DeQueue();
        Walk(node->x - 1, node->y, m, n, k);
        Walk(node->x + 1, node->y, m, n, k);
        Walk(node->x, node->y - 1, m, n, k);
        Walk(node->x, node->y + 1, m, n, k);
    }
    return g_walkCnt;
}

int movingCount(int m, int n, int k){
    Node start = {0, 0};
    EnQueue(&start);
    return Bfs(m, n, k);
}