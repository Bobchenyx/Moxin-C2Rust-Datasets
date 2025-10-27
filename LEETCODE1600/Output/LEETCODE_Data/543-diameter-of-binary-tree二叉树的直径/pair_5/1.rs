// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn depth(root: Option<Rc<RefCell<TreeNode>>>,ans: & mut i32) -> i32{
        match root {
            Some(node) => {
                let L = Solution::depth(node.clone().borrow().left.clone(),ans);
                let R = Solution::depth(node.clone().borrow().right.clone(),ans);
                *ans = std::cmp::max(*ans,L+R+1);
                std::cmp::max(L,R) + 1
            },
            None => 0
        }
    }
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans:i32 = 1;
        Solution::depth(root,&mut ans);
        ans - 1
    }
}