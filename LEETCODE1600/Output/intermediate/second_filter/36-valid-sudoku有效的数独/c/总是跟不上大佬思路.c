bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool isValid = true;
    int x[9][9] = {0};   //第一参数表示行号一共9行， 第二个参数标记0~8数字出现的次数
    int y[9][9] = {0};   //第一个参数表示列号一共9列，第二个参数标记0~8数字的出现次数
    int box[9][9] = {0}; //第一个参数表示将9*9的数独阵分成了0~8一共9块，第二个参数表示0~8数字出现的次数
    for(int i=0; i<9 && isValid; i++){
        for(int j=0; j<9 && isValid; j++){
            if(board[i][j]!='.'){
               int num = board[i][j]-'0'-1;  //将对应的字符数字转换为int，因为数独的数字是1~9,而数组保存的是0~8故-1
               ++x[i][num];                 //该数对应行的数组标记++
               ++y[num][j];                 //该数对应列的数组标记++ 
               //难难难难难难点： 把每个分区的元素映射到对应分区的下标 ：box_index = (row / 3) * 3 + columns / 3
               ++box[(i/3)*3+j/3][num];
               if(x[i][num]>1 || y[num][j]>1 || box[(i/3)*3+j/3][num]>1){
                   isValid = false;
                   break;
               }
            } 
        }
    }
    return isValid;
}