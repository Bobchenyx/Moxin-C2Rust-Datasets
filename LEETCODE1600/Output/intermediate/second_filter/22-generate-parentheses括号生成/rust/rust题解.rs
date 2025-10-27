impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        gp(n, 0, String::new()).collect()
    }
}
fn gp(l: i32, r: i32, prefix: String) -> Box<dyn Iterator<Item = String>> {
    match (l, r) {
        (0, 0) => Box::new(std::iter::once(prefix)),
        (l, 0) => Box::new(gp(l - 1, 1, prefix + "(")),
        (0, r) => Box::new(gp(0, r - 1, prefix + ")")),
        (l, r) => Box::new(gp(l - 1, r + 1, prefix.clone() + "(").chain(gp(l, r - 1, prefix + ")")))
    }
}