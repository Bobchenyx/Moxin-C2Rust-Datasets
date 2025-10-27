impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if a.len() == 0 {
            return vec![];
        }

        let h = a.len() as usize;
        let w = a[0].len() as usize;
        let mut res = Vec::new();

        for r in 0..w {
            let mut row = Vec::new();
            for c in 0..h {
                row.push(a[c][r]);
            }
            res.push(row);
        }
        res
    }
}