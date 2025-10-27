impl Solution {
    fn min_increment_for_unique(mut a: Vec<i32>) -> i32 {
        let mut res = 0;
        a.sort_unstable();
        let mut prev: Option<i32> = None;
        for val in a {
            if let Some(v) = prev {
                if val <= v {
                    res += v + 1 - val;
                    prev = Some(v + 1);
                } else {
                    prev = Some(val);
                }
            } else {
                prev = Some(val);
            }
        }
        res
    }
}