impl Solution {
    pub fn add_binary(mut a: String, mut b: String) -> String {
        let mut carry = 0;
        let mut res = String::new();
        loop {
            let (n1, n2) = (a.pop(), b.pop());
            
            if n1 == None && n2 == None { break; }
            
            let mut sum = carry;
            if let Some(x) = n1 {
                    sum += x.to_digit(2).unwrap();
            }
            if let Some(x) = n2 {
                sum += x.to_digit(2).unwrap();
            }
            
            carry = sum / 2;
            res.insert_str(0, &(sum % 2).to_string());
        }
        if carry > 0 { res.insert_str(0, &carry.to_string()); }
        res
    }
}