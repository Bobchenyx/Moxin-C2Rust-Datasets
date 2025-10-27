use std::collections::HashMap;
impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut distance:HashMap<Vec<i32>,i32> = HashMap::new();
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    distance.insert(vec![i as i32,j as i32],0);
                }
            }
        }
        let mut max = -1;
        for i in 0..(2 * n) {
            let mut have_member = false;
            for (k,v) in &distance.to_owned() {
                if *v == i as i32 {
                    have_member = true;
                    if k[0] as usize != 0 {
                        distance.entry(vec![k[0] - 1,k[1]]).or_insert((i + 1) as i32);
                    }
                    if k[0] as usize != n - 1 {
                        distance.entry(vec![k[0] + 1,k[1]]).or_insert((i + 1) as i32);
                    }
                    if k[1] as usize != 0 {
                        distance.entry(vec![k[0],k[1] - 1]).or_insert((i + 1) as i32);
                    }
                    if k[1] as usize != n - 1 {
                        distance.entry(vec![k[0],k[1] + 1]).or_insert((i + 1) as i32);
                    }
                }
            }
            if !have_member {
                if i == 1 {
                    return -1;
                }
                return (i as i32 - 1) as i32
            }
        }
        max
    }
}