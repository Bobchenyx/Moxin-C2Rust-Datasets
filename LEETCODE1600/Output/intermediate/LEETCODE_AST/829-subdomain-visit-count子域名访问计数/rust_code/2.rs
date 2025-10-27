use std::collections::HashMap;

pub fn subdomain_visits(cpdomains: Vec<String>) -> Vec<String> {
    let mut domain_counts = HashMap::new(); // HashMap<&str, usize>
    for cpdomain in &cpdomains {
        // 使用 find + slice 取代 split
        let space_idx = cpdomain.find(' ').unwrap();
        let count = &cpdomain[..space_idx].parse::<usize>().unwrap();
        let mut domain = &cpdomain[space_idx + 1..];

        // 每次把 domain 和对应的数量添加到 domain_counts 之后，
        // 都需要让 domain 指向下一个域名，即最左边的 '.' 后面的字符串；
        // 如果没有找到 '.'，就将 domain 置为空字符串，以结束循环。
        while !domain.is_empty() {
            *domain_counts.entry(domain).or_insert(0) += count;
            domain = domain.find('.').map_or("", |idx| &domain[idx + 1..]);
        }
    }

    domain_counts
        .into_iter()
        .map(|(domain, count)| format!("{} {}", count, domain))
        .collect()
}