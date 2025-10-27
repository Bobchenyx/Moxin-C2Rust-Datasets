impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let t = arr.len() / 4;
        for i in 0..arr.len() - 1 {
            if arr[i] == arr[i + t] {
                return arr[i];
            }
        }
        arr[0]
    }
}