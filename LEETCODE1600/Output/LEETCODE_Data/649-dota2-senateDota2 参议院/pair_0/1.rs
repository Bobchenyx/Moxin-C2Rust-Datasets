use std::collections::VecDeque;

impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let mut queue: VecDeque<bool> = senate.chars().map(|senator| senator == 'R').collect();
        let r_count = queue.iter().filter(|&&is_r| is_r).count();
        let d_count = senate.len() - r_count;
        let mut count = [r_count, d_count];
        let mut curr_balance = 0;
        while count[0] != 0 && count[1] != 0 {
          let curr_senator_is_r = queue.pop_front().unwrap();
          let curr = if curr_senator_is_r { 1 } else { -1 };
          if curr_balance * curr >= 0 {
            queue.push_back(curr_senator_is_r);
          } else { // one omitted
            count[if curr_senator_is_r { 0 } else {1}] -= 1;
          }
          curr_balance += curr;
        }
        // println!("{:?}, {} {}", queue, r_count, d_count);
        (if count[1] == 0 { "Radiant" } else { "Dire" }).to_string()
    }
}