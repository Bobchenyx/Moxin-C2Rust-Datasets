pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
    use std::collections::VecDeque;

    let mut ret = Vec::new();
    if root.is_none() {
        return ret;
    }
    let mut sub_vec = Vec::new();
    let mut queue = VecDeque::new();
    let mut cur_level = 0;
    queue.push_back((0, root.clone()));
    while !queue.is_empty() {
        if let Some((lev, Some(node))) = queue.pop_front() {
            if lev > cur_level {
                ret.push(sub_vec.clone());
                sub_vec.clear();
                cur_level = lev;
            }
            sub_vec.push(node.borrow().val);
            queue.push_back((lev + 1, node.borrow().left.clone()));
            queue.push_back((lev + 1, node.borrow().right.clone()));
        }
    }

    if !sub_vec.is_empty() {
        ret.push(sub_vec);
    }

    ret
}