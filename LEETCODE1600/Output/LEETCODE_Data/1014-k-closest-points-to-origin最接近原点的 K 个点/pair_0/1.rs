impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut points = points;
        points.sort_by_key(|p| p[0] * p[0] + p[1] * p[1]);
        let mut closest_k = Vec::new();
        for i in 0..k as usize {
            closest_k.push(points[i].clone());
        }
        closest_k
    }
}