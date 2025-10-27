use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        let mut vec = Vec::new();
        fn in_order(root: Option<Rc<RefCell<TreeNode>>>, k: i32, vec: &mut Vec<i32>) -> bool {
            if let Some(root) = root {
                let mut bool_ans = in_order(root.borrow().left.clone(), k, vec);
                if vec.contains(&(k - root.borrow().val)) {
                    return true;
                } else {
                    vec.push(root.borrow().val);
                }
                bool_ans = bool_ans || in_order(root.borrow().right.clone(), k, vec);
                return bool_ans;
            }
            false
        }
        in_order(root, k, &mut vec)
    }
}