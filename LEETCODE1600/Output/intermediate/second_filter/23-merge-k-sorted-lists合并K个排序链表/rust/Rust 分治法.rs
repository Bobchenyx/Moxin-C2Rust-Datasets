impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut lists = lists;
        let (len, mut interval) = (lists.len(), 1);

        if len == 0 {
            return None;
        }

        while interval < len {
            let mut i = 0;
            while i < len-interval {
                lists[i] = Self::merge_two_lists(lists[i].clone(), lists[i+interval].clone());
                i += interval*2;
            }
            interval *= 2;
        }
        
        lists[0].clone()
    }

    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>, 
        mut list2: Option<Box<ListNode>>) 
        -> Option<Box<ListNode>> {
        // Assume that the first node of list1 is smaller than that in list2
        if let None = list1 {
            // println!("list1 is empty");
            return list2;
        }
        if let None = list2 {
            // println!("list2 is empty");
            return list1;
        }
        
        let mut p1 = &list1;
        let mut p2 = &list2;
        let mut ans: Option<Box<ListNode>> = None;
        let mut p_ans = &mut ans;

        loop {
            let mut lesser_val = 0;
            let mut lesser_index = 1;
            
            if let None = p1 {
                while let Some(node_p2) = p2 {
                    *p_ans = Some(Box::new(ListNode::new(node_p2.val)));
                    if let Some(node) = p_ans {
                        p_ans = &mut node.next;
                    }
                    p2 = &node_p2.next;
                }
                break;
            }else if let Some(node) = p1 {
                lesser_val = node.val;
            }

            if let None = p2 {
                while let Some(node_p1) = p1 {
                    *p_ans = Some(Box::new(ListNode::new(node_p1.val)));
                    if let Some(node) = p_ans {
                        p_ans = &mut node.next;
                    }
                    p1 = &node_p1.next;
                }
                break;
            }else if let Some(node) = p2 {
                if lesser_val > node.val {
                    lesser_val = node.val;
                    lesser_index = 2;
                }
            }            

            *p_ans = Some(Box::new(ListNode::new(lesser_val)));
            if let Some(node) = p_ans {
                p_ans = &mut node.next;
            }
            
            match lesser_index {
                1 => if let Some(node) = p1 {
                    p1 = &node.next;
                },
                2 => if let Some(node) = p2 {
                    p2 = &node.next;
                },
                _ => panic!("lesser_index error!"),
            }

            // println!("lesser val is {}, lesser index is {}", lesser_val, lesser_index);
        }

        ans
    }
}