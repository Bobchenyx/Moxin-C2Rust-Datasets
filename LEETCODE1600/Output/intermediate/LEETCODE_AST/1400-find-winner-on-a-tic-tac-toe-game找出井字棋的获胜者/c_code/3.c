char * tictactoe(int** moves, int movesSize, int* movesColSize) {
        int i, flag[3][3] = {0}, r, c, sum1, sum2;
        int row1, row2, row3, col1, col2, col3;
        char *res = malloc(16);

        memset(res, 0, 16);
       // memset(flag,0,9*sizeof(int));
        for (i = 0; i < movesSize; i++) {
            r = moves[i][0];
            c = moves[i][1];
            flag[r][c] = (i%2?4:1);
        }
        sum1 = flag[0][0] + flag[1][1] + flag[2][2];
        sum2 = flag[0][2] + flag[1][1] + flag[2][0];
        row1 = flag[0][0] + flag[0][1] + flag[0][2];
        row2 = flag[1][0] + flag[1][1] + flag[1][2];
        row3 = flag[2][0] + flag[2][1] + flag[2][2];
        col1 = flag[0][0] + flag[1][0] + flag[2][0];
        col2 = flag[0][1] + flag[1][1] + flag[2][1];
        col3 = flag[0][2] + flag[1][2] + flag[2][2];

        //printf("%d %d %d %d %d %d %d %d\n", sum1, sum2, row1, row2, row3, col1, col2, col3);
        if(sum1 == 3 || sum2 == 3 || row1==3 || row2==3 || row3==3 || col1==3 || col2==3 || col3==3){
            res[0] = 'A';
            return res;
        }
       if(sum1==12 || sum2==12 || row1==12 || row2==12 || row3==12 || col1==12 || col2==12 || col3==12){
            res[0] = 'B';
            return res;
        }
    
        if(movesSize < 9){
            sprintf(res,"Pending");
            return res;
        } else {
             sprintf(res,"Draw");
            return res;
        }
}