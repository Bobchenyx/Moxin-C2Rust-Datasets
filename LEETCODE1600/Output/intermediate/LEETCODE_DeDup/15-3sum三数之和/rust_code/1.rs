fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // 不够三个数, 直接返回空数组
    if nums.len() < 3 {
        return vec![];
    }
    
    // 找不到头绪, 先排个序吧
    let mut nums = nums.clone();
    nums.sort();
    
    // 题目最后特别强调不能由重复的答案, 那就用 HashSet 来装它们
    let mut result = std::collections::HashSet::new();
    
    // 遍历, 先选定三数中的第一个数的坐标 a
    let mut a = 0;
    loop {
        // a 最多只能是整个数组里的倒数第三个数
        if a == nums.len()-2 {
            break;
        }
        // 三数中的第二个数的坐标 b, 从 a 后面开始
        let mut b = a + 1;
        loop {
            // b 最多是倒数第二数
            if b == nums.len()-1 {
                break;
            }
            // c 从 b 后面开始
            let mut c = b + 1;
            loop {
                // c 最多到倒数第一
                if c == nums.len() {
                    break;
                }
                // 如果三数相加得到 0, 就把 它们加到结果里. 注意 a, b, c 只是坐标
                if nums[a] + nums[b] + nums[c] == 0 {
                    let t = vec![nums[a], nums[b], nums[c]];
                    result.insert(t);
                }
                c += 1;
            }
            b += 1;
        }
        a += 1;
    }
    // 从 HashSet 转成 Vec, 满足题目
    result.into_iter().collect::<Vec<_>>()
}