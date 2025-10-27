class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x[9][9]={0};
        int y[9][9]={0};
        int chunk[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    x[i][num]++;
                    y[num][j]++;
                    chunk[num/3+(i/3)*3][num%3+(j/3)*3]++;
                    if(x[i][num]>1||y[num][j]>1|| chunk[num/3+(i/3)*3][num%3+(j/3)*3]>1) return false;
                }

            }   
        }
        return true;
    }
};