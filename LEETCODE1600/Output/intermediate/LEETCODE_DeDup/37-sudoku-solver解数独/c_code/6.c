class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) {
    vector<bitset<9>> a(9);    //行
    vector<bitset<9>> b(9);    //列
    vector<bitset<9>> box(9);  // box
    stack<pair<int, int>> pos;
    char cnum;
    int num;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cnum = board[i][j];
        num = cnum - '0' - 1;
        if (cnum != '.')
          a[i][num] = b[j][num] = box[i / 3 * 3 + j / 3][num] = 1;
      }
    }
    for (int i = 0, j = 0;;) {
      if (board[i][j] == '.') {
        for (int n = 1; n <= 10; ++n) {
          if (n <= 9 &&
              !(a[i][n - 1] | b[j][n - 1] | box[i / 3 * 3 + j / 3][n - 1])) {
            pos.push(make_pair(i, j));
            a[i][n - 1] = b[j][n - 1] = box[i / 3 * 3 + j / 3][n - 1] = 1;
            board[i][j] = n + '0';
            ++j;
            break;
          } else if (n >= 9) {
            auto t = pos.top();
            i = t.first;
            j = t.second;
            n = board[i][j] - '0';
            a[i][n - 1] = b[j][n - 1] = box[i / 3 * 3 + j / 3][n - 1] = 0;
            board[i][j] = '.';
            pos.pop();
          }
        }
      } else
        ++j;
      if (j == 9) {
        if (++i == 9) return;
        j = 0;
      }
    }
    return;
  }
};