const ascii_a: u8 = 'a' as u8;

impl Solution {
    pub fn common_chars(a: Vec<String>) -> Vec<String> {
        let mut freqs = vec![];
        for word in a {
            let mut freq = [0;26];
            for letter in word.chars() {
                let index = (letter as u8 - ascii_a) as usize;
                freq[index] += 1;
            }
            freqs.push(freq.clone());
        }
        let mut result = vec![];
        for i in 0..26 {
            let min = freqs.iter().map(|&f| f[i]).min().unwrap();
            for _ in 0..min {
                let i = i as u8;
                let letter = ((i + ascii_a) as char).to_string();
                result.push(letter.clone());
            }
        }
        result
    }
}