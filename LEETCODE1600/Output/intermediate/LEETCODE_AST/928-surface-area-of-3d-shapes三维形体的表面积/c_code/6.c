class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size = grid.size();
        int count = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                int v = grid[i][j];
                if(v != 0)
                    count += 2;
                if(i == 0)
                    count += v;
                else
                    count += max(v-grid[i-1][j],0);
                if(i == size - 1)
                    count+= v;
                else
                    count += max(v-grid[i+1][j],0);
                if(j == 0)
                    count += v;
                else
                    count += max(v-grid[i][j-1],0);
                if(j == size-1)
                    count += v;
                else
                    count += max(v-grid[i][j+1],0);
            }
        }
        return count;
    }
};