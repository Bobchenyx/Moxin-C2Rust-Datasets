#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

typedef struct _hash_st {
    int key;
    int val;
    UT_hash_handle hh;
}hash_st;

int helper(int a, int b) {
    return b == 0? a : helper(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if(deckSize <= 1) {
        return false;
    }

    hash_st *head = NULL;

    for(int i = 0; i < deckSize; i++) {
        int key = deck[i];

        hash_st *tmph;
        HASH_FIND(hh, head, &key, sizeof(key), tmph);
        if(tmph == NULL) {
            tmph = (hash_st *)calloc(1, sizeof(hash_st));
            tmph->key = key;
            tmph->val = 0;
            HASH_ADD_KEYPTR(hh, head, &tmph->key, sizeof(tmph->key), tmph);
        }

        tmph->val++;
    }

    int tar = -1;
    int last = -1;
    bool is_first = true;

    hash_st *hi0, *hi1;
    HASH_ITER(hh, head, hi0, hi1) {
        //printf("%d : %d\n", hi0->key, hi0->val);
        if(is_first) {
            is_first = false;
            last = hi0->val;
            continue;
        }
        
        tar = helper(hi0->val, last);
        last = hi0->val;

        //printf("tar = %d\n", tar);

        if(tar == 1 || (hi0->val % tar != 0)) {
            return false;
        }
    }

    return true;
}