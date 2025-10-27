fn access_dp(dp_a: &mut Vec<Vec<i32>>,dp:&Vec<Vec<Vec<i32>>>,x:i32,y:i32) -> bool {
    let m:i32 = dp_a.len() as i32;
    let n:i32 = dp_a[0].len() as i32;
    
    if x < 0 || y < 0 || x > m -1 || y > n - 1 || dp_a[x as usize][y as usize ] == -1 {
        return false;
    }
    let x = x as usize;
    let y = y as usize;
    if dp_a[x][y] == 1 {
        return true;
    }
    dp_a[x][y] = -1;
    let mut result:bool = false;
    if dp[x][y][0] == 1 {
        result = result || (x > 0 && dp[x - 1][y][2] == 1 && access_dp(&mut *dp_a,& *dp,(x - 1) as i32,y as i32))
    }
    if dp[x][y][1] == 1 {
        result = result || (y > 0 && dp[x][y - 1][3] == 1 && access_dp(&mut *dp_a,& *dp,x as i32,(y - 1) as i32))
    }
    if dp[x][y][2] == 1 {
        result = result || (x < (m - 1) as usize && dp[x + 1][y][0] == 1 && access_dp(&mut *dp_a,& *dp,(x + 1) as i32,y as i32))
        
    }
    if dp[x][y][3] == 1 {
        result = result || (y < (n - 1) as usize && dp[x][y + 1][1] == 1 && access_dp(&mut *dp_a,& *dp,x as i32,(y + 1) as i32))
    }
    if result {
        dp_a[x][y] = 1
    }
    return result;
}


impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp: Vec<Vec<Vec<i32>>> = vec![vec![vec![0;4];n];m];
        let mut dp_access:Vec<Vec<i32>> = vec![vec![0;n];m];
        for i in 0..m {
            for j in 0..n {
                match grid[i][j] {
                    1 => {
                        dp[i][j][1] = 1;
                        dp[i][j][3] = 1;
                    },
                    2 => {
                        dp[i][j][0] = 1;
                        dp[i][j][2] = 1;
                    },
                    3 => {
                        dp[i][j][1] = 1;
                        dp[i][j][2] = 1;
                    },
                    4 => {
                        dp[i][j][2] = 1;
                        dp[i][j][3] = 1;
                    },
                    5 => {
                        dp[i][j][1] = 1;
                        dp[i][j][0] = 1;
                    },
                    6 => {
                        dp[i][j][0] = 1;
                        dp[i][j][3] = 1;
                    },
                    _ => return false,
                }
            }
        }
        dp_access[0][0] = 1;
        return access_dp(&mut dp_access,&dp,(m - 1) as i32,(n - 1) as i32);
    }
}