#[derive(Copy, Clone)]
struct Fruit {
    tp: i32,
    count: i32,
}
impl Solution {
    pub fn total_fruit(tree: Vec<i32>) -> i32 {
        let len = tree.len();
        let mut fruit1 = Fruit { tp: len as i32, count: 0, };
        let mut fruit2 = Fruit { tp: len as i32, count: 0, };
        let mut continuing_fruit = Fruit { tp: len as i32, count: 0, };

        let mut max_count = 0;
        
        for fruit_tp in tree {
            // first in first out
            if fruit_tp == fruit1.tp { fruit1.count += 1; }
            else if fruit_tp == fruit2.tp { fruit2.count += 1; }
            else {
                fruit1 = continuing_fruit;
                fruit2.tp = fruit_tp;
                fruit2.count = 1;
            }
            let total_count = fruit1.count + fruit2.count;
            if max_count < total_count { max_count = total_count; }

            if fruit_tp == continuing_fruit.tp { 
                continuing_fruit.count += 1; 
            } else {
                continuing_fruit.tp = fruit_tp;
                continuing_fruit.count = 1;
            }
        } 
        max_count
    }
}