/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    //printf("%d",*returnSize);
    //candies=10;
    //num_people=3;
    int last_id,cnt,last_left,round;
    for(int i=1;;i++)
    {
        if((i+1)*i/2>candies)
        {
            cnt=i;  //记录等差数列的和在第几个数超过糖果数
          //  printf("%d\n",cnt);
            break;
        }
    }
    
    round=(cnt-1)/num_people; // 糖发完时经历的完整的轮数
    last_id=(cnt-1)%num_people;//最后一个人，领的糖不够，或者没领（前一个完整且刚好发完）
    last_left=candies-(cnt-1)*cnt/2; //最后一个人最后一次领的数量

    int *ans;
    //int ans[num_people];
    ans=(int *)malloc(num_people*sizeof(int));

    //y(i)=(i+1)*round+(0+r-1)*round/2*num_people=i*round+round+(round-1)*round/2*num_people
    int cst=round+(round-1)*round/2*num_people;
    for(int i=0;i<num_people;i++) //先把完整的轮数填满
    {
        ans[i]=i*round+cst;
        //printf("%d ",ans[i]);
    }

    //第round+1轮，把last_id前的糖给完，每人给i+1+(round+1-1)*n
    for(int i=0;i<last_id;i++)
    {
        ans[i]+=i+1+num_people*round;
    }

    ans[last_id]+=last_left; //最后一个人得剩下的糖
    /*
    for(int i=0;i<num_people;i++)
    {
        printf("%d ",ans[i]);
    }
    */
    *returnSize=num_people;
    return ans;
   // int a[4]={0};
   // return a;
}