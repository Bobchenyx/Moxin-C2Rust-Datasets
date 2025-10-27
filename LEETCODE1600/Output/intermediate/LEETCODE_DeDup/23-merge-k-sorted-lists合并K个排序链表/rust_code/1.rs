impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        if lists.is_empty() {
            return None;
        }
        let mut n = 0; 
        // compute length
        for mut ref_option in lists.iter() {
            while let Some(ref ref_box) = *ref_option {
                n += 1;
                ref_option = &ref_box.next;
            }
        }
        if n == 0 {
            return None;
        }

        // push into a vector
        let mut v = Vec::with_capacity(n);
        for mut ref_option in lists.iter() {
            while let Some(ref ref_box) = *ref_option {
                v.push(ref_box.val);
                ref_option = &ref_box.next;
            }
        }
        // sort
        v.sort();

        //generate a linklist
        let mut head = Some(Box::new(ListNode::new(v[0])));
        let mut prev: &mut Box<ListNode> = head.as_mut().unwrap();
        for &i in v[1..].iter() {
            prev.next = Some(Box::new(ListNode::new(i)));
            prev = prev.next.as_mut().unwrap();
        }
        head
    }
}