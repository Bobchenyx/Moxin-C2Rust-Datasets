const MORSEMAP: [&str; 26] = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--","-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."];

impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
		words
			.into_iter()
			.map(|word: String| {
				word.into_bytes()
					.into_iter()
					.map(|c: u8| String::from(MORSEMAP[(c - 'a' as u8) as usize]))
					.collect()
			})
			.collect::<std::collections::BTreeSet<String>>()
			.len() as i32
	}
}