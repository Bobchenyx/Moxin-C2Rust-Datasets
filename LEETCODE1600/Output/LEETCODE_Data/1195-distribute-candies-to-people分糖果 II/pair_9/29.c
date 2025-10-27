/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*num_people);
    for(int i=0;i<num_people;i++){
        ans[i]=0;
    }
    if(candies<=0){
        *returnSize=num_people;
        return ans;
    }
    int count=1;
    int dex=0;
    while(count<=candies){
        dex=dex%num_people;
        ans[dex]+=count;
        candies-=count;
        count++;
        dex++;
    }
    ans[dex%num_people]+=candies;
    *returnSize=num_people;
    return ans;
}