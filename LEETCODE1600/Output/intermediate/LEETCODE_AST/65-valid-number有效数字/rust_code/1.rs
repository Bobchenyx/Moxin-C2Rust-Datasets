rust
const TRANS_TABLE: [[usize;5];10] = [
    //[Op, Dig, Dot, Exp, Other]
    [1, 2, 9, 8, 8],//0
    [8, 2, 9, 8, 8],//1
    [8, 2, 3, 5, 8],//2:A
    [8, 4, 8, 5, 8],//3:A
    [8, 4, 8, 5, 8],//4:A
    [6, 7, 8, 8, 8],//5
    [8, 7, 8, 8, 8],//6
    [8, 7, 8, 8, 8],//7:A
    [8, 8, 8, 8, 8],//8
    [8, 4, 8, 8, 8],//9
];
const ACCEPT_STATE:[bool;10] = [false, false, true, true, true, false, false, true, false, false];
enum Code {
    Op = 0,
    Dig = 1,
    Dot = 2,
    Exp = 3,
    Other = 4,
}
impl Solution {
    pub fn is_number(s: String) -> bool {      
        let mut code = Code::Other;
        let mut state:usize = 0;
        let mut chars = s.trim().chars();
        loop {
            match chars.next() {
                Some('+')|Some('-') => { code = Code::Op; },
                Some('.') => { code = Code::Dot; },
                Some('e') => { code = Code::Exp; },
                Some(d) if d.is_digit(10) => { code = Code::Dig; },
                None => { break; },
                _ => { state = 8; break; },
            }
            state = TRANS_TABLE[state][code as usize];
        }
        ACCEPT_STATE[state]
    }
}