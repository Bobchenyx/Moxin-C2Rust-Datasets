/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ans=(int*)malloc(sizeof(int)*(num_people+1));
    int i,tmp=1,circle=0;
    memset(ans,0,sizeof(ans));
    while(candies){
        if(candies>(1+tmp*num_people)*(tmp*num_people)/2)
        {circle++;tmp++;}
        else
            break;
    }
    candies-=(1+circle*num_people)*(circle*num_people)/2;
    tmp=circle*num_people+1;
    for(i=0;i<num_people;i++){
        ans[i]=circle*(i+1)+num_people*circle*(circle-1)/2;
        if(candies>=tmp){
            ans[i]+=tmp;candies-=tmp;
            tmp++;
        }else{
            ans[i]+=candies;candies=0;
            tmp++;
        }
    }
    *returnSize=num_people;
    return ans;
}