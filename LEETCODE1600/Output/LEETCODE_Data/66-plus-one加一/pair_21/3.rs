impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut carry = 1;
        let mut nums:Vec<i32> = Vec::new();
        loop {
            let num = digits.pop();
            if num == None { break; }
            let new_num = num.unwrap() + carry;
            carry = new_num / 10;
            nums.insert(0, new_num % 10);
        }
        if carry > 0 { nums.insert(0, carry); }
        nums
    }
}