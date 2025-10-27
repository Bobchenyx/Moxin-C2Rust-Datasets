pub fn is_valid(s: String) -> bool {
    let mut v = Vec::new();
    s.len() & 1 == 0 && s.bytes().all(|b| Some(match b { b'(' | b'{' | b'[' => { v.push(b); return true }, b')' => b'(', b'}' => b'{', b']' => b'[', _ => panic!() }) == v.pop()) && v.is_empty()
}