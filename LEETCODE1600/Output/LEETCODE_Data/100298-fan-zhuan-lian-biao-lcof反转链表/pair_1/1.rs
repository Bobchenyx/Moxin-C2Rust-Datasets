impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut last = None;
        let mut cur = head;
        loop {
            if let Some(mut node) = cur {
                // node 是一个 Box 指针, 这里省略了 *
                cur = node.next;
                node.next = last;
                last = Some(node);
            } else {
                break;
            }
        }
        last 
    }
}