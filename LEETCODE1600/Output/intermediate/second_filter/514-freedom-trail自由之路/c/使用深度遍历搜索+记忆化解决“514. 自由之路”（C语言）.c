#include <limits.h>
#define MMIN(a, b)      ((a) < (b)? (a) : (b))

char *rr;
int rlen;
char *kk;
int klen;

int memo[100][100];

//返回从rid，和kid的位置遍历完序列的最小步骤
int helper(int rid, int kid) {
    if(kid == klen) {
        return 0;
    }

    if(memo[rid][kid] != 0) {
        return memo[rid][kid] - 1;
    }

    int min_steps = INT_MAX;
    int cur_steps = 0;

    //遍历ring，找到所有的相同位置
    for(int i = 0; i < rlen; i++) {
        //实际访问位置
        int id = (rid + i) % rlen;
        if(rr[id] == kk[kid]) {
            cur_steps = MMIN(i, rlen - i);

            int ret = helper(id, kid + 1);

            min_steps = MMIN(min_steps, ret + cur_steps);
        }
    }

    memo[rid][kid] = min_steps + 1;

    return min_steps;
}

//【算法思路】DFS。
int findRotateSteps(char * ring, char * key){
    rr = ring;
    rlen = strlen(ring);
    kk = key;
    klen = strlen(key);

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            memo[i][j] = 0;
        }
    }

    int ret = helper(0, 0);

    return ret + klen;
}