void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(*boardColSize == 0 || boardSize == 0){
        return;
    }
    int c[boardSize][*boardColSize];
    int dx[] = {1,-1,0,0,1,-1,1,-1};
    int dy[] = {0,0,1,-1,1,-1,-1,1};
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<(*boardColSize);j++){
            c[i][j] = board[i][j];
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<(*boardColSize);j++){
            int count = 0;
            for(int k=0;k<8;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=boardSize || y>=(*boardColSize)){
                    continue;
                }
                if(c[x][y] == 1){
                    count++;
                }
            }
            if((c[i][j] == 0 && count == 3) || (c[i][j] == 1 && (count == 2 || count == 3))){
                board[i][j] = 1;
            }else{
                board[i][j] = 0;
            }
        }
    }
}