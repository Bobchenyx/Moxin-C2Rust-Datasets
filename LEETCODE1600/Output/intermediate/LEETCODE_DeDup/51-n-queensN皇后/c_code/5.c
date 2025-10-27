/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>

#define N 100
#define MAX 120000
#define ND 3
int dirs[ND][2] = { {-1, 0}, {-1, -1}, {-1, 1} };

bool used[N][N];

bool check_dir(int x, int y, int dx, int dy, int n) {
    int nx, ny;
    bool ret = true;

    for (;;) {
        nx = x + dx;
        ny = y + dy;

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            break;
        }

        if (used[nx][ny]) {
            ret = false;
            break;
        }

        x = nx;
        y = ny;
    }

    return ret;
}

bool check(int x, int y, int n) {
    int i;
    bool ret = true;

    for (i = 0; i < ND; i++) {
        ret = check_dir(x, y, dirs[i][0], dirs[i][1], n);
        if (!ret) {
            return ret;
        }
    }
    return ret;
}

void dfs(int idx, int n, char ***res, int *sol_cnt) {
    int i, j;
    char **arr = NULL;

    if (idx >= n) {
        arr = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++) {
            arr[i] = (char *)malloc((n + 1) * sizeof(char));
            for (j = 0; j < n; j++) {
                if (used[i][j] == 1) {
                    arr[i][j] = 'Q';
                } else {
                    arr[i][j] = '.';
                }
            }
            arr[i][j] = '\0';
        }
        res[*sol_cnt] = arr;
        (*sol_cnt) += 1;
        return;
    }

    for (i = 0; i < n; i++) {
        if (!check(idx, i, n)) {
            continue;
        }

        used[idx][i] = true;
        dfs(idx + 1, n, res, sol_cnt);
        used[idx][i] = false;
    }
}


char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***res = NULL;
    int i, j, k;
    
    res = (char ***)malloc(MAX * sizeof(char **));
    (*returnColumnSizes) = malloc(MAX * sizeof(int));
    
    memset(used, 0, sizeof(used));
    *returnSize = 0;
    dfs(0, n, res, returnSize);

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return res;
}