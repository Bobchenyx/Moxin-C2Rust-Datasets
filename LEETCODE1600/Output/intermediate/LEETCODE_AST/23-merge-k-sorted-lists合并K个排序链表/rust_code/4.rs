use std::collections::BinaryHeap;
impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &ListNode) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for ListNode {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.val.cmp(&self.val)
    }
}
pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    if lists.is_empty() { return None }
    let mut heap = BinaryHeap::with_capacity(lists.len());
    for l in lists {
        if let Some(l) = l {
            heap.push(l);
        }
    }

    let mut dummy = ListNode::new(0);
    let mut p  = &mut dummy;
    while !heap.is_empty() {
        let mut min_l = heap.pop().unwrap();
        if heap.is_empty() {
            p.next = Some(min_l);
            break;
        }
        let next = min_l.next.take();
        if next.is_some() {
            heap.push(next.unwrap());
        }
        p.next = Some(min_l);
        p = p.next.as_deref_mut().unwrap();
    }
    dummy.next
}