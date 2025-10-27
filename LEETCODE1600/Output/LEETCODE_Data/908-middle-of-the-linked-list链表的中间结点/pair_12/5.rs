// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::rc::Weak;
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut fast = &head;
        let mut slow = &head;

        while let Some(ref node) = *fast {
            fast = &node.next;
            if let Some(ref next) = fast {
                fast = &next.next;
            } else {
                break;
            }

            if let Some(ref s) = *slow {
                if s.next.is_some() {
                    slow = &s.next;
                }
            }
        }

        slow.clone()
    }
}