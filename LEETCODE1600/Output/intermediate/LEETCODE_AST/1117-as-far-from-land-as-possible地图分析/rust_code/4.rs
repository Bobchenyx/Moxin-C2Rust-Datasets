impl Solution {
    pub fn max_distance(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut queue : Vec<(usize,usize)> = Vec::new();
        let mut ans = -1;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == 1 {
                    queue.push((i, j));
                }
            }
        }
        if queue.len() == grid.len() * grid.len() || grid.len() == 0 {
            return ans;
        }

        while !queue.is_empty() {
            let que_len = queue.len();
            for _ in 0..que_len {
                let (x,y) = queue.remove(0);
                if x > 0 && grid[x-1][y] == 0 {
                    grid[x-1][y] = -1;
                    queue.push((x-1,y));
                }
                if x < grid.len() -1 && grid[x+1][y] == 0 {
                    grid[x+1][y] = -1;
                    queue.push((x+1,y));
                }
                if y > 0 && grid[x][y-1] == 0 {
                    grid[x][y-1] = -1;
                    queue.push((x,y-1));
                }
                if y < grid.len() - 1 && grid[x][y+1] == 0 {
                    grid[x][y+1] = -1;
                    queue.push((x,y+1));
                }
            }
            ans += 1;
        }
        ans
    }
}