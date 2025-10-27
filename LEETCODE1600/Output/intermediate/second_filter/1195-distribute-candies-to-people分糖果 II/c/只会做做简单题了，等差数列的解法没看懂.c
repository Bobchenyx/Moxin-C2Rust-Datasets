/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* a = (int* )malloc(num_people*sizeof(int));
    memset(a,0,num_people*sizeof(int));
    int dis = 0;
    int index = -1;
    int canditmp = candies;
    while(canditmp>0){
        dis++;
        index++;
        a[index%num_people]+=dis;
        canditmp-=dis;
    }
    a[index%num_people]+=canditmp;
    *returnSize = num_people;
    return a;
}