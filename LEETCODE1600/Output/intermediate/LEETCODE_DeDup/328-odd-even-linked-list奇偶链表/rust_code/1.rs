impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut odd = vec![];
        let mut even = vec![];
        let mut is_odd = true;
        let mut head = head;
        while let Some(mut inner) = head {
            if is_odd {
                odd.push(inner.val);
            } else {
                even.push(inner.val);
            }
            is_odd = !is_odd;
            head = inner.next.take();
        }

        // note if we don't want to use reference, we need to construct
        // the ListNode in reverse order.
        let mut cur = None;
        for &v in even.iter().rev() {
            let mut node = ListNode::new(v);
            node.next = cur;
            cur = Some(Box::new(node));
        }

        for &v in odd.iter().rev() {
            let mut node = ListNode::new(v);
            node.next = cur;
            cur = Some(Box::new(node));
        }

        cur
    }
}