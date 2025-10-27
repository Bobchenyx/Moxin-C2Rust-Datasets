pub fn consecutive_numbers_sum(s: i32) -> i32 {
        let mut count = 1;
        let double_s = s * 2;
        let mut p = 2;
        while p*(p+1) <= double_s {
        // p是否为2s的因子?
            if double_s%p == 0 {
                let q = double_s/p ;
                // m,n同时为偶数吗?
                if (p+q-1)%2 == 0 && (p-q+1)%2 == 0 {
                    count += 1;
                }
            }
            p += 1;
        }
        count
    }
}