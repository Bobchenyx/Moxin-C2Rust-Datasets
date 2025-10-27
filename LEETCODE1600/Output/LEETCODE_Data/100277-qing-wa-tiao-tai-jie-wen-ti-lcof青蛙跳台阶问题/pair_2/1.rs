rust []
impl Solution {
    pub fn num_ways(n: i32) -> i32 {
        let (mut a, mut b) = (0, 1);
        for _ in 0 .. n + 1 {
            let c = a;
            a = b;
            b = (a + c) % 1000000007;
        }
        a
    }
}