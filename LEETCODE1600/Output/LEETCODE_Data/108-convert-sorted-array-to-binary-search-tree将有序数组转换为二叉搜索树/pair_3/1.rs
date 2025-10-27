// 此函数左闭右开，初始时
// start = 0, end = array.len()
arrary_to_bst(array, start, end) -> Option<TreeNode> {
    if start >= end {
        return None;
    } else {
        let mid = (start + end) / 2;
        let node = TreeNode::new(array[mid]);
        // 递归构建左叶，注意把 mid 作为 end
        node.left = array_to_bst(array, start, mid);
        // 递归构建右叶
        node.right = array_to_bst(array, mid + 1, end);
        Some(node)
    }
}