impl Solution {
    pub fn min_increment_for_unique(a: Vec<i32>) -> i32 {
        if a.is_empty() {
            return 0;
        }
        let mut a = a;
        a.sort();
        let mut min = 0;
        let mut k = a[0];
        for i in a {
            if k >= i {
                min += k - i;
                k += 1;
            } else {
                k = i + 1;
            }
        }
        min
    }
}