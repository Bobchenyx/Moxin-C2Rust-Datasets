pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
    nums.sort_unstable();
    closest_n_sum(&nums, target, 3)
}

fn closest_n_sum(nums: &[i32], target: i32, n: usize) -> i32 {
    if n == 1 {
        closest_num(nums, target)
    } else {
        let mut closest_sum: Option<i32> = None;
        for i in 0..=nums.len() - n {
            let num = nums[i];
            let sum = num + closest_n_sum(&nums[i + 1..], target - num, n - 1);
            if sum == target {
                return target;
            }
            let cs = closest_sum.get_or_insert(sum);
            if (*cs - target).abs() > (sum - target).abs() {
                *cs = sum;
            }
        }
        closest_sum.unwrap()
    }
}

fn closest_num(nums: &[i32], target: i32) -> i32 {
    let mut i = 0;
    let mut j = nums.len() - 1;

    if target < nums[i] {
        return nums[i];
    } else if target > nums[j] {
        return nums[j];
    }

    while j - i > 1 {
        let mid = (i + j) / 2;
        if target > nums[mid] {
            i = mid;
        } else if target < nums[mid] {
            j = mid;
        } else {
            return target;
        }
    }
    if target - nums[i] > nums[j] - target {
        nums[j]
    } else {
        nums[i]
    }
}