impl Solution {
    pub fn largest_time_from_digits(a: Vec<i32>) -> String {
        let mut a = a;
        a.sort();
        a.reverse();
        for i in 0..4 {
            if a[i] > 2 {
                continue;
            }

            for j in 0..4 {
                if j == i || (a[i] == 2 && a[j] > 3) {
                    continue;
                }

                for k in 0..4 {
                    if k == i || k == j || a[k] > 5 {
                        continue;
                    }

                    return format!("{}{}:{}{}", a[i], a[j], a[k], a[6 - i - j - k]);
                }
            }
        }
        "".to_string()
    }
}