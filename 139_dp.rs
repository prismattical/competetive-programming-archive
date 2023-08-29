struct Solution {}

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut tab = vec![false; s.len() + 1];
        tab[0] = true;

        for index in 0..tab.len() - 1 {
            if !tab[index] {
                continue;
            }

            for word in word_dict.iter() {
                let chop =
                    s[index..std::cmp::min(index + word.chars().count(), s.len())].to_string();
                if word.to_string() == chop {
                    tab[index + word.len()] = true;
                }
            }
        }

        println!("{:?}", tab);

        return tab.last().copied().unwrap();
    }
}

fn main() {
    let s = "catsandog".to_string();
    let word_dict = vec![
        "cats".to_string(),
        "dog".to_string(),
        "sand".to_string(),
        "and".to_string(),
        "cat".to_string(),
    ];

    let s = "leetcode".to_string();
    let word_dict = vec!["leet".to_string(), "code".to_string()];
    Solution::word_break(s, word_dict);
}
