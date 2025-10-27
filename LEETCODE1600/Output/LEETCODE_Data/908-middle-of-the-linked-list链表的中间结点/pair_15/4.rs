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
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut slow,mut quick)=(head.clone(),head.clone());
        while  quick!=None && quick.as_ref().unwrap().next!=None {
            slow=slow.as_ref().unwrap().next.clone();
            quick=quick.as_ref().unwrap().next.clone().as_ref().unwrap().next.clone();
        }
        slow
    }
}