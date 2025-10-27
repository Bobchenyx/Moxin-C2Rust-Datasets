pub fn longest_palindrome(s: String) -> String {
    let ss: Vec<char> = s.chars().collect();
    let len = ss.len();
    if len <= 1 {
        return s;
    }

    let (mut begin, mut end, mut left, mut right, mut max) = (0, 0, 0, 0, 0);
    for i in 0..len {
        left = i;
        right = i;
        while left > 0 && ss[left - 1] == ss[i] {
            left -= 1;
        }
        while right < len - 1 && ss[right + 1] == ss[i] {
            right += 1;
        }

        while left > 0 && right < len - 1 && ss[left - 1] == ss[right + 1] {
            left -= 1;
            right += 1;
        }
        if right - left > max {
            begin = left;
            end = right;
            max = end - begin;
        }
    }

    s[begin..end + 1].to_string()
}