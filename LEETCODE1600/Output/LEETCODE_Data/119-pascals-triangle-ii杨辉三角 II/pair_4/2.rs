impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let row_index = row_index as usize;
        let mut v: Vec<i32> = (0..=row_index).map(|_| 1).collect();
        for r in 2..=row_index {
            let mut y = v[0];
            for c in 1..r {
                let x = v[c];
                v[c] += y;
                y = x;
            }
        }
        v
    }
}