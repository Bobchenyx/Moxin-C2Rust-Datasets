use std::collections::HashMap;
 use std::collections::HashSet;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut set: HashSet<i32> = HashSet::new();
        let len = arr.len();

        for i in 0..len {
            set.insert(arr[i]);
        }
        for item in set {
            map.insert(item, 0);
        }
        for i in 0..len {
            if let Some(x) = map.get_mut(&arr[i]) {
                *x += 1;
            }
        }
        let mut _set: HashSet<i32> = HashSet::new();
        for item in map.values() {
            _set.insert(*item);
        }
        (_set.len() == map.len())
    }
}