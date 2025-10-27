pub fn eval_op(digit: &mut Vec<i32>, op:&mut Vec<char>) {
        loop {
            match op.pop() {
                | Some('(') => {break;},
                | Some('*') => {
                    let d1 = digit.pop();
                    let d2 = digit.pop();
                    match (d1,d2) {
                        (Some(x),Some(y)) => digit.push(x*y),
                        _ => panic!("NO NUMBER IN STACK")
                    };
                },
                | Some('+') => {
                    let d1 = digit.pop();
                    let d2 = digit.pop();
                    match (d1,d2) {
                        (Some(x),Some(y)) => digit.push(x+y),
                        _ => panic!("NO NUMBER IN STACK")
                    };
                },
                | Some(_) => {panic!("Illegal op");},
                | _ => {break;}
            }
        }
    }
    pub fn score_of_parentheses(s: String) -> i32 {
        let mut digit:Vec<i32> = vec![];
        let mut op:Vec<char> = vec![];

        let mut s_iter = s.chars().peekable();
        while let Some(c) = s_iter.next(){
            match s_iter.peek() {
                | Some(&n) => {
                    match (c,n) {
                        | ('(','(') => {
                            digit.push(2);
                            op.push('(');
                            op.push('*');
                            //println!("{:?} {:?}",&digit, &op);
                          },
                        | ('(',')') => {
                            digit.push(1);
                            op.push('(');
                            //println!("{:?} {:?}",&digit, &op);
                        },
                        | (')','(') => {
                            Solution::eval_op(&mut digit, &mut op);
                            op.push('+');
                            //println!("{:?} {:?}",&digit, &op);
                        },
                        | (')',')') => {
                            Solution::eval_op(&mut digit, &mut op);
                            //println!("{:?} {:?}",&digit, &op);
                        },
                        | _ => {panic!("Wrong");}
                    }
                  },
                | None => {
                    Solution::eval_op(&mut digit, &mut op);
                    //println!("{:?} {:?}",&digit, &op);
                  }
            }
        };
        Solution::eval_op(&mut digit, &mut op);
        digit.pop().unwrap()
    }