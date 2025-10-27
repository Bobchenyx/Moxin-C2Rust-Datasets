impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = vec![];
        for ch in s.chars() {
            if stack.is_empty() {
                stack.push(ch);
            } else {
                match ch {
                    '(' | '[' | '{' => stack.push(ch),
                    ')' | ']' | '}' => {
                        if (ch == ')' && *stack.last().unwrap() == '(')
                            || (ch == ']' && *stack.last().unwrap() == '[')
                            || (ch == '}' && *stack.last().unwrap() == '{')
                        {
                            stack.pop();
                        } else {
                            break;
                        }
                    }
                    _ => (),
                }
            }
        }
        stack.is_empty()
    }
}