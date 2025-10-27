impl Solution { 
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> { 
        let mut node = head; 
        let mut res = None;
        while let Some(t) = node { 
            res = Some(Box::new(ListNode{val: t.val, next: res}));  
            node = t.next; 
        }
        res 
    } 
}