#define MAX(a, b) ((a)>(b)?(a):(b))
#define MAXSIZE 55001

int leastBricks(int **wall, int wallSize, int *wallColSize)
{
    //把每一列对应的位置给出，就是从前往后累加
    for (int i = 0; i < wallSize; i++) {
        for (int j = 1; j < wallColSize[i]; j++) {
            wall[i][j] += wall[i][j - 1];
        }
    }

    int map[MAXSIZE] = {0};

    for (int i = 0; i < wallSize; i++) {
        for (int j = 0; j < wallColSize[i]-1; j++) {
            map[wall[i][j]]++;
        }
    }

    int max = 0;

    //统计出现平度最高的词个数，用wallsize去减
    for (int i = 0; i < MAXSIZE; i++) {
        max = MAX(max, map[i]);
    }

    return wallSize-max;
}