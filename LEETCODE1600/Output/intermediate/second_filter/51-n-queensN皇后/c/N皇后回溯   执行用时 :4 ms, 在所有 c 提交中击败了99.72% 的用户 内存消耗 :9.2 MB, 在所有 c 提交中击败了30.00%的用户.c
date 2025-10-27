void search(char ***answer,int *returnSize,int n,char**plate,int *col,int *firstdiagonal,int *seconddiagonal,int index)
 {//answer是三维答案数组，returnSize 是有几个答案，n是n皇后，plate是棋盘
 //index是第几行，从0开始，firstdiagonal是主对角线标记数组，second diagonal是次对角线标记数组，col是列表数组
     int i=0,post=0,j=0;
      if(index==n)
      {
          answer[*returnSize]=(char**)malloc(sizeof(char*)*n);//为每一个二维答案数组申请空间
          for(i=0;i<n;i++)
              answer[*returnSize][i]=(char*)malloc(sizeof(char)*(n+1));
          for(i=0;i<n;i++)
          {
              for(j=0;j<n;j++)
                 answer[*returnSize][i][j]=plate[i][j];
              answer[*returnSize][i][j]='\0';
          }
          *returnSize+=1;
          return ;
      }
      for(i=0;i<n;i++)//寻找第一个列位置
      {
          if(index-i<0)
              post=index-i+(2*n-1);
          else
               post=index-i;
           if(firstdiagonal[post]==0 && seconddiagonal[index+i]==0 &&col[i]==0)//该位置可以放
           {
               plate[index][i]='Q';
               firstdiagonal[post]=1;
               seconddiagonal[index+i]=1;
               col[i]=1;
               search(answer,returnSize,n,plate,col,firstdiagonal,seconddiagonal,index+1);
               plate[index][i]='.';
               firstdiagonal[post]=0;
               seconddiagonal[index+i]=0;
               col[i]=0;
           }
                  
      }

 }
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***answer=NULL;
    answer=(char***)malloc(sizeof(char**)*1000);//答案数组
    int i=0,j=0,k=0;
    *returnSize=0;//结果个数
     (*returnColumnSizes) = malloc(1000 * sizeof(int));//三维结果数组中 每一个二维结果数组的列数数组
    char **plate=(char**)malloc(sizeof(char*)*n);//棋盘
    int *col=(int*)malloc(sizeof(int)*n);//当前列是否存在皇后
    int *firstdiagonal=(int*)malloc(sizeof(int)*2*n);//当前位置主对角线是否存在皇后
    int *seconddiagonal=(int*)malloc(sizeof(int)*2*n);//当前位置次对角线是否存在皇后
    for(i=0;i<n;i++)//赋初始值 表示不存在皇后
        col[i]=0;
    for(i=0;i<2*n;i++)//赋初始值 表示不存在皇后
        firstdiagonal[i]=0;
    for(i=0;i<2*n;i++)//赋初始值 表示不存在皇后
        seconddiagonal[i]=0;
    for(i=0;i<n;i++)//给棋盘数组的每一列分配空间
        plate[i]=(char*)malloc(sizeof(char)*n);
    for(i=0;i<n;i++)//生成初始棋盘
    {
        for(j=0;j<n;j++)
            plate[i][j]='.';
    }
    search(answer,returnSize,n,plate,col,firstdiagonal,seconddiagonal,0);
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    for (i = 0; i < *returnSize; i++) 
        (*returnColumnSizes)[i] = n;
   return answer;
}