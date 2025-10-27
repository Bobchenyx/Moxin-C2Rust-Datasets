#define A_MAX 40000
int minIncrementForUnique(int* A, int ASize){
    int i = 0 ;
    int move_cnt =0;
    int A_array[A_MAX]={0};
    int move_num = 0;
    for(i=0;i<ASize;i++)
    {
        A_array[A[i]]++;
    }
    for(i=0;i<A_MAX-1;i++)
    {
        if(A_array[i]>=2)
        {
            move_num = A_array[i]-1;
            move_cnt+= move_num;
            A_array[i+1]+=move_num;
            A_array[i]=1;
        }
    }
    if(A_array[i]>=2)
    {
         move_num = A_array[i]-1;
         for(i=1;i<=move_num;i++)
         {
             move_cnt+= i;
         }
    }
    return move_cnt;
}