impl Solution {
    pub fn remove_subfolders(folder: Vec<String>) -> Vec<String> {
        let mut  f = folder.clone();
        f.sort_by(|a, b| a.cmp(&b));
        let mut v = vec![];
        let mut current_parent = &f[0];
        for i in 1..f.len() {
            let item = &f[i];
            let t = item.get(..current_parent.len() + 1);
            if !item.contains(current_parent) ||
                (item.contains(current_parent) && !(t.is_some() && t.unwrap().ends_with("/"))) {
                v.push(current_parent.to_string());
                current_parent = item;
            }

            if i + 1 == f.len() {
                v.push(current_parent.to_string());
            }
        }
        v
    }
}