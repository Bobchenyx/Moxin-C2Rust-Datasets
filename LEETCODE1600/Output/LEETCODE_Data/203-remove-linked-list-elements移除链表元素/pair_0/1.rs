type Link = Option<Box<ListNode>>;

impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut h = Some(Box::new(ListNode::new(-1)));
        h.as_mut().unwrap().next = head;
        let mut head = h;
        
        let mut p = &mut head;
        
        while let Some(node) = &mut p.as_mut().unwrap().next {
            if node.val == val {
                p.as_mut().unwrap().next = node.next.take();
            }else {
                p = &mut p.as_mut().unwrap().next;
            }
        }

        head.unwrap().next
    }
}