use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p,q) {
            (None, None) => true,
            (None, _) | (_,None) => false,
            (Some(pr),Some(qr)) => {
                let (pr,qr) = (pr.as_ref(), qr.as_ref()); // & RefCell
                let (pr,qr) = (pr.borrow(), qr.borrow()); // & TreeNode 
                if pr.val == qr.val {
                    Self::is_same_tree(pr.left.clone(),qr.left.clone()) && Self::is_same_tree(pr.right.clone(),qr.right.clone())
                }else{
                    false
                }
            }
        }
    }
}