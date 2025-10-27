#define MAX_NUM 111

typedef struct {
    int x;
    int y;
    int height;
} Node;

Node g_list[MAX_NUM * MAX_NUM] = {0};
bool g_visited[MAX_NUM * MAX_NUM] = {false};
int g_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Compare(const void *value1, const void *value2)
{
    return ((Node *)value1)->height - ((Node *)value2)->height;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
    int i;
    int head = 0;
    int tear = 0;
    int result = 0;
    Node topNode;
    Node nextNode;

    if (heightMapSize <= 0) {
        return 0;
    }

    (void)memset(g_visited, 0, sizeof(bool) * heightMapSize * heightMapColSize[0]);
    for (i = 0; i < heightMapSize; i++) {
        g_list[tear].x = 0;
        g_list[tear].y = i;
        g_list[tear].height = heightMap[i][0];
        tear++;
        g_list[tear].x = heightMapColSize[0] - 1;
        g_list[tear].y = i;
        g_list[tear].height = heightMap[i][heightMapColSize[0] - 1];
        tear++;
        g_visited[i * heightMapColSize[0]] = true;
        g_visited[i * heightMapColSize[0] + heightMapColSize[0] - 1] = true;
    }
    for (i = 1; i < heightMapColSize[0] - 1; i++) {
        g_list[tear].x = i;
        g_list[tear].y = 0;
        g_list[tear].height = heightMap[0][i];
        tear++;
        g_list[tear].x = i;
        g_list[tear].y = heightMapSize - 1;
        g_list[tear].height = heightMap[heightMapSize - 1][i];
        tear++;
        g_visited[i] = true;
        g_visited[(heightMapSize - 1) * heightMapColSize[0] + i] = true;
    }

    while (tear > head) {
        qsort(g_list + head, tear - head, sizeof(Node), Compare);
        topNode = g_list[head];
        head++;

        for (i = 0; i < 4; i++) {
            nextNode.x = topNode.x + g_dir[i][0];
            nextNode.y = topNode.y + g_dir[i][1];
            if (nextNode.x < 0 || nextNode.x >= heightMapColSize[0] || nextNode.y < 0 || nextNode.y >= heightMapSize) {
                continue;
            }
            if (g_visited[nextNode.y * heightMapColSize[0] + nextNode.x]) {
                continue;
            }
            g_visited[nextNode.y * heightMapColSize[0] + nextNode.x] = true;
            nextNode.height = heightMap[nextNode.y][nextNode.x];
            // if wall height is bigger than inner height, means can fill water
            if (nextNode.height < topNode.height) {
                result += topNode.height - nextNode.height;
            }
            g_list[tear].x = nextNode.x;
            g_list[tear].y = nextNode.y;
            // use the max height as the wall
            g_list[tear].height = nextNode.height > topNode.height ? nextNode.height : topNode.height;
            tear++;
        }
    }

    return result;
}