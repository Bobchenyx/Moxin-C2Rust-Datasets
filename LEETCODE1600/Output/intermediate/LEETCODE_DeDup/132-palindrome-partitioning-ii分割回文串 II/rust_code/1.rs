impl Solution {
    pub fn min_cut(s: String) -> i32 {
        let n = s.len();
        if n==0 {
            return 0;
        }
        let mut f = vec![0; n+1];
        let chars = s.chars().collect::<Vec<char>>();
        let palin_dp = get_palindrome_dp(&chars);
        for i in 1..=n {
            f[i] = i32::max_value();
            for j in 0..i {
                if palin_dp[j][i-1] && f[j]+1 < f[i] {
                    f[i] = f[j]+1;
                }
            }
        }
        f[n]-1
    }
}

//判断l~j之间的字符串是否回文串
pub fn get_palindrome_dp(chars: &Vec<char>) -> Vec<Vec<bool>> {
    let n = chars.len();
    let mut dp = vec![vec![false; n]; n];
    let n = n as i32;
    for i in 0..n {
        //奇数
        let (mut l, mut r) = (i, i);
        while l>=0 && r<n && chars[l as usize] == chars[r as usize] {
            dp[l as usize][r as usize] = true;
            l -= 1;
            r += 1;
        }

        //偶数
        let (mut l, mut r) = (i, i+1);
        while l>=0 && r<n && chars[l as usize] == chars[r as usize] {
            dp[l as usize][r as usize] = true;
            l -= 1;
            r += 1;
        }
    }
    dp
}