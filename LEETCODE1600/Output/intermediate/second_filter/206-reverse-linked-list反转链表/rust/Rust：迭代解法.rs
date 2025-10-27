impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut old_list = head;
        let mut new_list: Option<Box<ListNode>> = None;
        
        while old_list.is_some() {
            let mut node = old_list.unwrap();
            let rem = node.next.take();
            node.next = new_list;
            new_list = Some(node);
            old_list = rem;
        }

        new_list
    }
}