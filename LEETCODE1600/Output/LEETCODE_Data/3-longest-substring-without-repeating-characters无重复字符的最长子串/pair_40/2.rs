use std::collections::VecDeque;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut queue: VecDeque<u8> = VecDeque::new();
        let mut count: Vec<i32> = Vec::new();

        for item in s.bytes() {
            if queue.contains(&item) {
                let len = queue.len();
                count.push(len as i32);
                while queue.contains(&item) {
                    queue.pop_front();
                }
            }
            queue.push_back(item);
        }
        let len = queue.len();
        count.push(len as i32);

        (*count.iter().max().unwrap())
    }
}