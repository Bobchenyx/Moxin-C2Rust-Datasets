pub fn find_content_children(g: Vec<i32>, s: Vec<i32>) -> i32 {
        let mut sort_g:Vec<i32> = g.clone();
        sort_g.sort();
        let mut sort_s = s.clone();
        sort_s.sort();
        let mut index = 0;
        let mut count = 0;

        'outer: for ch in sort_g.iter(){
            for ck in index..sort_s.len(){
                if sort_s[ck] >= *ch {
                    count += 1;
                    index = ck;
                    sort_s.remove(ck);
                    continue 'outer;
                }
            }
            return count;
        }

        count
    }