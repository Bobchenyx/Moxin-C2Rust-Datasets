use std::collections::HashMap;
use std::i32;
impl Solution {
    pub fn gcd(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }
        a
    }

    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut cm = HashMap::new();
        let mut mcd = 0;
        for num in deck.iter() {
            let counter = cm.entry(num).or_insert(0);
            *counter += 1;
            if(mcd < *counter) {
                mcd = *counter;
            }
        }

        for val in cm.values() {
            if(*val == 1) {
                return false;
            }
            mcd = Solution::gcd(*val, mcd);
        }

        if(mcd == 0 || mcd == 1) {
            return false;
        } 

        true
    }
}