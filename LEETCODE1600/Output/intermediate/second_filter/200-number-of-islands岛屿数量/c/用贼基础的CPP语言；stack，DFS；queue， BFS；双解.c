C++ [-C++]
class Solution {
public:
    bool inGrid(vector<vector<char>>& grid, pair <int,int> a) //判断点是否超出边界
    {
        if(a.first >= 0 && a.first < grid.size() && a.second >= 0 && a.second < grid[0].size())
            return true;
        else 
            return false;
    }
    
    void DFS(vector<vector<char>>& grid, stack<pair<int,int>>& po) //DFS的过程
    {
        if(po.empty()) return;
        pair <int,int> temp = po.top();
        po.pop();
        grid[temp.first][temp.second] = '0';
        pair <int,int> up = {temp.first + 1, temp.second}; 
        pair <int,int> down = {temp.first - 1, temp.second};
        pair <int,int> left = {temp.first, temp.second - 1};
        pair <int,int> right = {temp.first, temp.second + 1};
        if(inGrid(grid,up) && grid[temp.first + 1][temp.second] == '1') //若拓展出去的点仍在边界之内，且是岛屿的一部分，将其push入栈内，作为之后迭代的起始点
            po.push(up);
        if(inGrid(grid,down) && grid[temp.first - 1][temp.second] == '1')
            po.push(down);
        if(inGrid(grid,left) && grid[temp.first][temp.second - 1] == '1')
            po.push(left);
        if(inGrid(grid,right) && grid[temp.first][temp.second + 1] == '1')
            po.push(right);
        return DFS(grid,po);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        stack <pair<int,int>> po;
        if(grid.empty()) return 0; //若地图为空，直接返回0
        int m = grid.size();
        int n = grid[0].size();
        for(int y = 0; y < m; ++y) //遍历整张地图的每个点
        {
            for(int x = 0; x <n; ++x)
            {
                if(grid[y][x] == '1') //若bool值为true，该点为新发现的岛屿的起始点
                {
                    po.push({y,x});
                    DFS(grid,po); //进入深度优先搜索
                    ++ans; //岛屿数加一
                }
            }
        }
        return ans;
    }
};