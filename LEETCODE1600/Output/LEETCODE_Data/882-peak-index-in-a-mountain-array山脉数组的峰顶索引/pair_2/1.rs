impl Solution {
        pub fn peak_index_in_mountain_array(a: Vec<i32>) -> i32 {
        let mut index = 0i32;
        let len = a.len();

        for i in 1..len {
            if a[i] > a[i - 1] {
                continue;
            } else {
                index = i as i32 - 1;
                break;
            }
        }

        (index)
    }
}