#define MAX_WORD_LEN 300
#define MAX_COL_SIZE 6
typedef struct Pos_{
    int x;
    int y;
}Pos;
Pos GetPos(char ch){
    Pos res;
    char c = ch - 'A';
    res.x = c / MAX_COL_SIZE;
    res.y = c % MAX_COL_SIZE;
    return res;
}
void PrintDist(int distNum, Pos dist[distNum]){
    for (int i = 0; i < distNum; i++){
        printf("%d:%d ", dist[i].x, dist[i].y);
    }
    printf("\n");
}
#define MIN(a, b) ((a) < (b) ? (a):(b))
#define GetDist(a, b) (abs(a.x - b.x) + abs(a.y - b.y))
int g_mem[MAX_WORD_LEN][26][26];
#define GetIndex(n)  (n.x * MAX_COL_SIZE + n.y)
int GetMinDist(Pos firstPos, Pos secondPos, Pos dist[], int start, int end){
    //printf("[%d:%d]\n", start, end);
    if(start >= end){
        return 0;
    }
    int fi = GetIndex(firstPos);
    int se = GetIndex(secondPos);
    if (g_mem[start][fi][se] != -1){
        return g_mem[start][fi][se];
    }
    int disFirst = GetDist(dist[start], firstPos) + GetMinDist(dist[start], secondPos, dist, start + 1, end);
    int disSecond = GetDist(dist[start], secondPos) + GetMinDist(firstPos, dist[start], dist, start + 1, end);
    g_mem[start][fi][se] =  MIN(disFirst, disSecond);
    return g_mem[start][fi][se];
}
int minimumDistance(char * word){
    Pos dist[MAX_WORD_LEN] = {0};
    int distNum = 0;
    char *p = word;
    while(*p != '\0'){
        dist[distNum++] = GetPos(*p);
        p++;
    }

    for (int i = 0; i < strlen(word); i++){
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                g_mem[i][j][k] = -1;
            }
        }
    }
    //PrintDist(distNum, dist);
    Pos firstPos = dist[0];
    Pos secondPos = {.x = -1, .y = -1};
    //循环第二个手指的开始点，计算最优的情况
    int min = INT_MAX;
    //printf("distNum:%d\n", distNum);
    for (int i = 1; i < distNum; i++){
        firstPos = dist[0];
        secondPos = dist[i];
        int curTimes = GetMinDist(firstPos, secondPos, dist, 0, distNum);
        //printf("curTimes, min [%d:%d]\n", curTimes, min);
        min = MIN(min, curTimes);
    }
    return min;
}