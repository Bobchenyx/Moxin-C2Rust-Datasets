impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let (mut l, mut r) = (0, 0);
        let mut res = String::new();
        for i in s.chars() {
            if i == '(' {
                l += 1;
            } else {
                r += 1;
            }

            if l == r {
                l = 0;
                r = 0;
            } else if l > 1 {
![image.png](https://pic.leetcode-cn.com/ee8f3c24251708979fb9892d1874eaf1729d0887bab2c5368ec5d1131cb32023-image.png)
                res.push(i);
            }
        }
        res
    }
}