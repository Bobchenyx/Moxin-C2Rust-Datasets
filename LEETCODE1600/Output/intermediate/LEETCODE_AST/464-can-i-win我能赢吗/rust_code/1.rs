impl Solution {
    pub fn can_i_win(max_choosable_integer: i32, desired_total: i32) -> bool {
        let can_reach = (max_choosable_integer+1)*max_choosable_integer/2;
        if can_reach < desired_total {
            return false;
        }
        if can_reach == desired_total {
            return max_choosable_integer&1 == 1;
        }
        let mut f = vec![None; 1<<(max_choosable_integer as usize)];
        Self::dfs(0, max_choosable_integer, desired_total, &mut f)
    }
    fn dfs(cur: i32, range: i32, target: i32, f: &mut Vec<Option<bool>>) -> bool {
        // cur代表current的状态，range是可以取的最大的数，target是我们累加的目标
        let ucur = cur as usize;
        if let Some(ok) = f[ucur] {
            return ok;
        }
        for i in (1..=range).rev() {
            // 枚举接下来取哪个数
            let cur_bit = 1<<(i-1);
            // 如果这个数没被取过
            if cur & cur_bit == 0 {
                // 如果直接取就能达成目标，取它就完事儿了
                // 或者，如果我取了i，然后该另一个人取数了，并且他输了，那么我就赢了
                if i >= target || !Self::dfs(cur | cur_bit, range, target-i, f) {
                    f[ucur] = Some(true);
                    return true;
                }
            }
        }
        // 怎么取都赢不了，那我就输了
        f[ucur] = Some(false);
        false
    }
}