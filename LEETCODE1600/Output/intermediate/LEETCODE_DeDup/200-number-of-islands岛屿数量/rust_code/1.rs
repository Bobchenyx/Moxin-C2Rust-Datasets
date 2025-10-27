python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not len(grid) or not len(grid[0]):
            return 0
        m, n = len(grid), len(grid[0])
        f = lambda i, j: not (grid[i].__setitem__(j, None),
            j + 1 < n and grid[i][j + 1] == '1' and f(i, j + 1),
            j > 0 and grid[i][j - 1] == '1' and f(i, j - 1),
            i + 1 < m and grid[i + 1][j] == '1' and f(i + 1, j),
            i > 0 and grid[i - 1][j] == '1' and f(i - 1, j))
        return sum(grid[i][j] == '1' and not f(i, j) for i, j in itertools.product(range(m), range(n)))