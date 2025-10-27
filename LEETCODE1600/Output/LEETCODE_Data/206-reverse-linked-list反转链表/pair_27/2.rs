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
    pub fn reverse_list(srcnode:Option<Box<ListNode>>) -> Option<Box<ListNode>>{
        
        let mut current; 
        let mut last;
        
        match srcnode {
            Some(mut p) =>{ 
                current = p.next;
                p.next = None;
                last = Some(p);
            },
            None => {return srcnode;}
        };
        
        while let Some(mut pcur) = current {
            current = pcur.next;
            pcur.next = last;
            last = Some(pcur);
        }
        last
    }
}