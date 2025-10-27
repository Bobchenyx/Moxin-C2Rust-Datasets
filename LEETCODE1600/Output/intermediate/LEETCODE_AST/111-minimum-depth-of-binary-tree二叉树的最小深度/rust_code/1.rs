use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() { // special case: []
            0
        } else{
            let (l,r) = (root.as_ref().unwrap().borrow().left.clone(),root.as_ref().unwrap().borrow().right.clone());
            match (l,r) {
                (None, None) => 1,
                (None, nd) | (nd,None) => 1+Self::min_depth(nd),
                (l,r) => 1+std::cmp::min(Self::min_depth(l),Self::min_depth(r))   
            }
        }
    }
}