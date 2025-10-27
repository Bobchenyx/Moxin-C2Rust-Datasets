use std::cmp::min;

impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let len = chips.len();

        let mut even_count = 0i32;
        for item in chips {
            if 0 == item & 0x01 {
                even_count += 1;
            }
        }

        min(even_count, len as i32 - even_count)
    }
}