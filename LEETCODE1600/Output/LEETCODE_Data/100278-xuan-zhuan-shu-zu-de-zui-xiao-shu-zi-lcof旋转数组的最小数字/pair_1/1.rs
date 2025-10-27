rust []
impl Solution {
    pub fn min_array(numbers: Vec<i32>) -> i32 {
        let (mut i, mut j) = (0, numbers.len() - 1);
        while i < j {
            let k = (i + j) / 2;
            if numbers[k] > numbers[j] {
                i = k + 1
            } else if numbers[k] < numbers[j] {
                j = k
            } else {
                j -= 1
            }
        }
        numbers[i]
    }
}