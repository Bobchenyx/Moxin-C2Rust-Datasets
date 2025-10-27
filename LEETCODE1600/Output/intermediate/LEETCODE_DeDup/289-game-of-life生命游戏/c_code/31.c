int aliveAround(int** Board,int BoardSize,int* BoardColSize, int Row,int Col)
{
    int result=0;
    if(Row-1>=0)
    {
        if(Col-1>=0&&(Board[Row-1][Col-1]==1||Board[Row-1][Col-1]==-1))++result;
        if(Board[Row-1][Col]==1||Board[Row-1][Col]==-1)++result;
        if(Col+1<BoardColSize[Row-1]&&(Board[Row-1][Col+1]==1||Board[Row-1][Col+1]==-1))++result;
    }
    if(Row+1<BoardSize)
    {
        if(Col-1>=0&&(Board[Row+1][Col-1]==1||Board[Row+1][Col-1]==-1))++result;
        if(Board[Row+1][Col]==1||Board[Row+1][Col]==-1)++result;
        if(Col+1<BoardColSize[Row+1]&&(Board[Row+1][Col+1]==1||Board[Row+1][Col+1]==-1))++result;
    }
    if(Col-1>=0&&(Board[Row][Col-1]==1||Board[Row][Col-1]==-1))++result;
    if(Col+1<BoardColSize[Row]&&(Board[Row][Col+1]==1||Board[Row][Col+1]==-1))++result;
    return result;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    for(int row=0;row<boardSize;++row)
        for(int col=0;col<boardColSize[row];++col)
            {
                int num=aliveAround(board,boardSize,boardColSize,row,col);
                if(board[row][col]==1) 
                    if(num<2||num>3)
                        board[row][col]=-1;   
                if(num==3&&board[row][col]==0)
                    board[row][col]=-2;
            }

    for(int row=0;row<boardSize;++row)
        for(int col=0;col<boardColSize[row];++col)
            if(board[row][col]==-1)board[row][col]=0;
            else if(board[row][col]==-2)board[row][col]=1;
}