bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int HashRow[9][10];
    int HashCol[9][10];
    int HashBox[9][10];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            HashRow[i][j]=0;
            HashCol[i][j]=0;
            HashBox[i][j]=0;
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                HashRow[i][board[i][j]-'0']++;
                HashCol[j][board[i][j]-'0']++;
                HashBox[(i/3)*3+(j/3)][board[i][j]-'0']++;
                bool b1=HashRow[i][board[i][j]-'0']>1;
                bool b2=HashCol[j][board[i][j]-'0']>1;
                bool b3=HashBox[(i/3)*3+(j/3)][board[i][j]-'0']>1;
                if(b1||b2||b3) return false;
            }
        }
    }
    /* for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("Row[%d][%d]=%d ",i,j,HashRow[i][j]);
            printf("Col[%d][%d]=%d ",i,j,HashCol[i][j]);
            printf("Box[%d][%d]=%d ",i,j,HashBox[i][j]);
        }
    }*/
    return true;
}