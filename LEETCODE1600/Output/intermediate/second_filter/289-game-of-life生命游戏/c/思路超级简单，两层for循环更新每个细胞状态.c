//判断该坐标有效且存活返回1 ，无效或者是死细胞返回0
int coordislive(int** board_copy,int boardSize, int boardColSize,int row,int col)
{
    if((row<0)||(row >= boardSize)||(col <0)||(col >= boardColSize)) //出界 return0
        return 0 ;
    else
        return board_copy[row][col];
}
//判断周围活细胞个数
int livenum(int** board_copy,int boardSize, int* boardColSize,int row,int col)//board_copy[i][j]周围坐标的个数
{
    int ret=0;
    ret = coordislive(board_copy, boardSize, boardColSize[0], row+1, col) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col) + \
          coordislive(board_copy, boardSize, boardColSize[0], row, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row, col-1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col-1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row+1, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row+1, col-1) ;
    return ret ;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    
    //1 复制board
    int** board_copy ; //用于保存原始记录
    board_copy = (int**) malloc(boardSize*sizeof(int*));
    for(int i=0;i < boardSize;i++){
        board_copy[i] = (int*) malloc(boardColSize[i]*sizeof(int*));
        for(int j= 0;j<boardColSize[i];j++){
            board_copy[i][j] = board[i][j];
        }
    } 
    //2 开始更新细胞状态
    for(int i=0;i < boardSize;i++){
        for(int j= 0;j<boardColSize[i];j++){
            int tmp = livenum(board_copy,boardSize, boardColSize,i,j);
            //3 按照活细胞个数更新细胞状态
            if(board_copy[i][j]==1){ //细胞是活的
                if((tmp < 2)||(tmp > 3)) //如果活细胞数少于两个或者大于3个，则该位置活细胞死亡
                    board[i][j] = 0;
            }
            else{
                if(tmp == 3) //正好3个复活
                    board[i][j] = 1;  
            }
        }
    }
    
}