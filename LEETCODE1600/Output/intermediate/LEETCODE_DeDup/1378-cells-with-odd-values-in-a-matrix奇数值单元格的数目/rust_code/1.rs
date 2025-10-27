impl Solution {
    pub fn odd_cells(n: i32, m: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut arr = vec![vec![0; m as usize]; n as usize];

        for item in indices {
            for i in 0..m {
                arr[item[0] as usize][i as usize] += 1;
            }

            for i in 0..n {
                arr[i as usize][item[1] as usize] += 1;
            }
        }

        let mut count = 0i32;
        for i in 0..n {
            for j in 0..m {
                if arr[i as usize][j as usize] % 2 == 1 { count += 1; }
            }
        }

        (count)
    }
}