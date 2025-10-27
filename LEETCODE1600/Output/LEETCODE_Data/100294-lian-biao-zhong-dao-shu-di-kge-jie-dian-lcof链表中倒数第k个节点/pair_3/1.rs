type Link = Option<Box<ListNode>>;

impl Solution {
    pub fn get_kth_from_end(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut left = &mut head as *mut Link;
        let mut right = left;

        unsafe {
            let move_p = |mut x: *mut Link, k: i32| {
                for _ in 0..k {
                    if *x == None {
                        return x;
                    }else {
                        x = &mut (*x).as_mut().unwrap().next as *mut Link;
                    }
                }
                x
            };

            right = move_p(right, k);

            while *right != None {
                left = move_p(left, 1);
                right = move_p(right, 1);
            }

            (*left).take()
        }

    }
}