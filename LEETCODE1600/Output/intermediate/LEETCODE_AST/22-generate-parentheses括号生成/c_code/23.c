#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

/**
 * Note: The returned array just be jalloced, assuje caller calls free().
 */

typedef struct _info_st {
    char *s;
    struct _info_st *nxt;
}info_st;

//【算法思路】DFS + 单链表。卡塔兰数，使用单链表组织结果
char ** generateParenthesis(int n, int* returnSize){
    if(n == 0) {
        *returnSize = 1;
        char **ret = (char **)calloc(1, sizeof(char*));
        ret[0] = "";
        return ret;
    };

    info_st *head = NULL;
    int rsize = 0;

    for(int i = 0; i < n; i++) {
        int lnum = i;
        int rnum = n - 1 - i;

        int lcnt, rcnt;
        char **tmpl = generateParenthesis(lnum, &lcnt);
        char **tmpr = generateParenthesis(rnum, &rcnt);

        for(int j = 0; j < lcnt; j++) {
            for(int k = 0; k < rcnt; k++) {
                info_st *new = (info_st *)calloc(1, sizeof(info_st));
                new->s = (char *)calloc(n * 2 + 1, sizeof(char));

                //开始填充结果
                int sid = 0;
                new->s[sid++] = '(';
                strncpy(&new->s[sid], tmpl[j], lnum * 2);
                sid += lnum * 2;
                new->s[sid++] = ')';
                strncpy(&new->s[sid], tmpr[k], rnum * 2);

                //printf("%s\n", new->s);

                new->nxt = head;
                head = new;
                rsize++;
            }
        }
    }

    char **ret = (char **)calloc(rsize, sizeof(char *));
    int rid = 0;

    info_st *cur = head;

    while(cur != NULL) {
        ret[rid++] = cur->s;
        cur = cur->nxt;
    }

    *returnSize = rsize;
    return ret;
}