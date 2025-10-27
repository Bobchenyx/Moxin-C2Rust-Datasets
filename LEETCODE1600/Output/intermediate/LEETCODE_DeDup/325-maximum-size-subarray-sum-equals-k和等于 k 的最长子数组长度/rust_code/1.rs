use std::collections::HashMap;
use std::cmp::max;

impl Solution {
    pub fn max_sub_array_len(nums: Vec<i32>, k: i32) -> i32 {
        // total 表示前缀和
        let mut total = 0;
        let mut hash = HashMap::new();
        let n = nums.len();
        let mut ans = 0;
        for (i, v) in nums.into_iter().enumerate() {
            total += v;
            let q = total-k;
            // 如果当前和就等于k，那就找到了一个从0..i的区间，由于i是递增的，因此ans就是i+1
            if q == 0 {
                ans = i+1;
            } else if let Some(&idx) = hash.get(&q) {
                // 看前面是否存在0..idx的区间，和为q，确定这个idx
                // 如果找到了，说明存在一个长度为i-idx的区间和为k
                ans = max(ans, i-idx);
            }
            // 利用hash表记录以下和为total的区间最短是0..i
            // 这里利用了rust的entry方法，相当于是如果hash[total]不存在再插入i，否则不做任何处理（因为要求最长区间，因此需要保存最短的0..i）
            hash.entry(total).or_insert(i);
        }
        ans as i32
    }
}