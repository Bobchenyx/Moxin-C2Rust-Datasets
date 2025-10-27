impl Solution {
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let len = a.len();
        for i in 0..(len - 2) {
            if a[i] == a[i + 1] || a[i] == a[i + 2] {
                return a[i];
            }
        }
        a[len - 1]
    }
}