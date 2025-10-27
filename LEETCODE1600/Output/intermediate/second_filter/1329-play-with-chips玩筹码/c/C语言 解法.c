int minCostToMoveChips(int* chips, int chipsSize){
    int even_num = 0; //偶数位置的筹码个数
    int add_num = 0;  //奇数位置的筹码个数
    int i=0;
    for(i=0;i<chipsSize;i++)
    {
        if(chips[i]%2 == 0)
        {
            even_num++;
        }
        else
        {
            add_num++;
        }
    }
    return even_num>add_num?add_num:even_num; // 代价就是偶数和奇数位置中的最小筹码数
}