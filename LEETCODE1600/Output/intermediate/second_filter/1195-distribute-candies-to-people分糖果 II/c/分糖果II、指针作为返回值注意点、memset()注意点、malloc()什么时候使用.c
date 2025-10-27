/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int X=1,i=0;
    int *result;
    result=(int*)malloc(sizeof(int)*num_people);
    memset(result,0,sizeof(int)*num_people);
    while(X<=candies){
        result[i%num_people]+=X;
        candies-=X;
        i++;
        X++;
    }
    if(candies>0) result[i%num_people]+=candies;

    *returnSize=num_people;
    return result;
}