pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    use std::collections::{BinaryHeap, HashMap};
    let len = nums.len();
    if len == 0 {
        return Vec::new();
    }
    if len == 1 {
        return nums;
    }
    let mut map: HashMap<i32, i32> = HashMap::new();
    for i in nums {
        let count = map.e***y(i).or_insert(0);
        *count += 1;
    }
    let mut heap = BinaryHeap::new();
    for v in map.iter() {
        heap.push((v.1, v.0));
    }
    let mut ret: Vec<i32> = Vec::new();

    for _ in 0..k {
        ret.push(heap.pop().unwrap().1.to_owned());
    }

    ret
}