int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i,j,k,sign=0,result=0;
    int s1=0,s2=0,s3=0,s4=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='R'){
                sign=1;
                break;
            }
        }
        if(sign==1) break;
    }
    for(k=1;k<8;k++){
        if(s1==0&&i-k>=0){
            s1=board[i-k][j]=='B'?1:0;
            if(board[i-k][j]=='p'){
                result++;
                s1=1;
            }
        }
        if(s2==0&&i+k<8){
            s2=board[i+k][j]=='B'?1:0;
            if(board[i+k][j]=='p'){
                result++;
                s2=1;
            }
        }
        if(s3==0&&j-k>=0){
            s3=board[i][j-k]=='B'?1:0;
            if(board[i][j-k]=='p'){
                result++;
                s3=1;
            }
        }
        if(s4==0&&j+k<8){
            s4=board[i][j+k]=='B'?1:0;
            if(board[i][j+k]=='p'){
                result++;
                s4=1;
            }
        }
        if(s1==1&&s2==1&&s3==1&&s4==1) break;
    }
    return result;
}