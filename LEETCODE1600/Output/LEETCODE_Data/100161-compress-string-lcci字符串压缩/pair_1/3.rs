impl Solution {
pub fn compress_string(s: String) -> String {
    let mut new = String::new();
    let mut count = 0;
    let mut character = ' ';
    for i in s.chars() {
        if i == character {
            count = count+1;
            continue;
        }
        if count != 0 {
            new.push(character);
            new.push_str(&count.to_string());
        
            character = i;
            count =1;
                continue;
        }

        character = i;
        count = count+ 1;
    }

    new.push(character);
    new.push_str(&count.to_string());
    println!("{}-{}",s,new);
    if new.chars().count() >= s.chars().count() {
        return s
    }
    new
}
}