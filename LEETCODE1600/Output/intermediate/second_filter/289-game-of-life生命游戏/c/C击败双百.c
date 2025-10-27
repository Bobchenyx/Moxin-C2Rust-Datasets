void gameOfLife(int** board, int boardSize, int* boardColSize){
    int new_row = boardSize +2;
    int new_col = *boardColSize+2;
    int new_board[new_row][new_col];
    //把board的元素填入new_board，新加的邻居设为0
    for(int i=0; i<new_row; i++) {
        for(int j=0; j<new_col; j++) {
            if(i>=1 && i<= boardSize && j>=1 && j<=*boardColSize) {
                new_board[i][j] = board[i-1][j-1];
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    //检索new_board中填入的board
    for(int i=1; i<=boardSize; i++){
        for(int j=1; j<=*boardColSize; j++){
            if(new_board[i][j]==0){
                int cont1 = 0;
                for(int m=i-1; m<=i+1; m++) {
                     for(int n=j-1; n<=j+1; n++) {
                         if(new_board[m][n]==1) {
                              cont1++;
                        }
                     }
                }
                if(cont1==3){
                    board[i-1][j-1]=1;
                }
            }else{
                int cont2 = -1;  //-1是因为下面的循环计算中会加上本来的那个1
                for(int m=i-1; m<=i+1; m++) {
                     for(int n=j-1; n<=j+1; n++) {
                         if(new_board[m][n]==1) {
                                 cont2++;
                        }
                     }
                }
                if(cont2<2 || cont2>3){
                    board[i-1][j-1]=0;
                }
            }
        }
    }
}