pub fn total_fruit_dp(tree: Vec<i32>) -> i32 {
        let n = tree.len();
        let mut i = 0;
        let mut j = i;

        // to begin, let's try to find the first two blocks
        while j < n && tree[j]==tree[i] {j+=1;}
        let mut ans = j-i;
        let mut pp = (tree[i], ans, ans); // pp stores the first block, but from the third block's point of view, it's prepre, so pp
        i = j;
        if i >= n {
            return ans as i32;
        }
        // find the second block
        while j < n && tree[j] == tree[i] {j+=1;}
        ans += j-i;
        let mut p = (tree[i], ans, j-i); // from the third block's point of view, it's pre, so p
        i = j;
        while i < n {
            let mut j = i;
            // find current block
            while j < n && tree[i] == tree[j] {j+=1;}
            let len = j-i;
            if tree[i] == pp.0 { // if value == block[i-2].value
                pp = p;
                p = (tree[i], pp.1+len, len);
                ans = ans.max(p.1);
            } else {
                pp = p;
                p = (tree[i], pp.2+len, len);
                ans = ans.max(p.1);
            }
            i = j;
        }
        ans as i32
    }