impl Solution {
    pub fn distribute_candies(mut candies: i32, num_people: i32) -> Vec<i32> {
        fn min(i: i32, j: i32) -> i32 {
            if (i <= j) {
                i
            } else {
                j
            }
        }
        let (mut res, row, once) = (Vec::new(), num_people * num_people, num_people * (num_people + 1) / 2);
        let mut step = 0;
        while (candies >= step * row + once) {
            candies -= step * row + once;
            step += 1;
        }
        for i in 0..num_people {
            res.push(step * (i + 1) + step * (step - 1) / 2 * num_people - min(-min(step * num_people + i + 1, candies), 0));
            candies -= step * num_people + i + 1;
        }
        res
    }
}