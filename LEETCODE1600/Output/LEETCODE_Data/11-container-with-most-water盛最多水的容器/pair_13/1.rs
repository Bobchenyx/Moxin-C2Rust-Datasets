pub fn max_area(height: Vec<i32>) -> i32 {
        let compute_area = |min_height: i32, step: i32| -> i32 { min_height * step };
        let min_value = |a: i32, b: i32| -> i32 { if a > b { b } else { a } };
        let mut max_area = 0_i32;
        for (i, n) in height.iter().enumerate() {
            let mut j = i + 1;
            while let Some(&j_value) = height.get(j) {
                if let Some(&i_value) = height.get(i) {
                    let temp = compute_area(min_value(i_value, j_value), (j - i) as i32);
                    if temp > max_area { max_area = temp }
                }
                j += 1;
            }
        }
        max_area
    }