#define MAX 1000000

int g_flag[MAX];

bool BFS(int x, int y, int z, int left)
{
    if (left < 0) {
        return false;
    }

    if (left == z || left + x == z || left + y == z || x - (y - left) == z || y - (x - left) == z) {
        return true;
    }

    if (g_flag[left] == 1) {
        return false;
    }

    g_flag[left] = 1;
    return BFS(x, y, z, x - left) || BFS(x, y, z, y - left) || BFS(x, y, z, left - x) || BFS(x, y, z, left - y);
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) {
        return false;
    }

    memset(g_flag, 0, sizeof(g_flag));
    return BFS(x, y, z, 0);
}