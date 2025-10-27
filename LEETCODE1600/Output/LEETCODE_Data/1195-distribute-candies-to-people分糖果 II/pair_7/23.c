/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * num_people);
    (void)memset(ret, 0, sizeof(int) * num_people);
    *returnSize = num_people;

    int round = (int)(sqrt(8*(long long)candies+1)-1)/(2*num_people);

    int i;
    for (i=0; i<num_people; i++) {
        ret[i] = (i+1+i+1+(round-1)*num_people)*round/2;
    }

    int remain = candies - round*num_people*(round*num_people+1)/2;
    if (!remain) return ret;

    for (i=0; i<num_people; i++) {
        if (remain > round*num_people+i+1) {
            ret[i] += (round*num_people+i+1);
            remain -= (round*num_people+i+1);
        } else {
            ret[i] += remain;
            break;
        }
    }
    return ret;
}