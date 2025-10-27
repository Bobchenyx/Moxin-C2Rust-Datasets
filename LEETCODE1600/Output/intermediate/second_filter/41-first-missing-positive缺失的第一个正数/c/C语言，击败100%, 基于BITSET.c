#include <limits.h>        /* for CHAR_BIT */
#include <string.h>
#include <stdlib.h>

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))

int firstMissingPositive(int *nums, int numsSize);


int firstMissingPositive(int *nums, int numsSize) {
    u_char *table = malloc(numsSize/8 + 1);
    memset(table, 0, numsSize/8 + 1);
    if (nums == NULL) {
        return -1;
    }

    int *step = nums;
    int size = numsSize;
    while (size-- > 0) {
        //非正整数跳过
        if (*step > 0 && *step <= (numsSize + 1)) {
            BITSET(table, *step);
        }
        step++;
    }


    int result;
    for (result = 1; result <= numsSize; result++) {
        if (!BITTEST(table, result)) {
            free(table);
            return result;
        }
    }
    free(table);
    return result;
}