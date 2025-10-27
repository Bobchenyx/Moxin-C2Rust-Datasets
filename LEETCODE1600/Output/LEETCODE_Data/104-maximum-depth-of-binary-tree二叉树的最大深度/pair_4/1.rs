pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        use std::collections::VecDeque;
        if root.is_none(){
            return 0;
        }
        let mut max_depth = 0;
        let mut queue = VecDeque::new();
        queue.push_back((1, root.clone()));
        while !queue.is_empty() {
            if let Some((depth, Some(node))) = queue.pop_front(){
                if depth > max_depth {
                    max_depth = depth;
                }
                queue.push_back((depth + 1, node.borrow().left.clone()));
                queue.push_back((depth + 1, node.borrow().right.clone()));
            }
        }

        max_depth
    }