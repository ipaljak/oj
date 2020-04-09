use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn check(x: usize, s: &String) -> bool {
    let mut curr = 0;
    for (i, c) in s.chars().enumerate() {
        if c == 'R' && curr + x >= i + 1 {
            curr = i + 1;
        }
    }
    curr + x > s.len()
}

fn solve(s: String) -> usize {
    let mut lo = 1;
    let mut hi = s.len() + 1;
    while lo < hi {
        let mid = (lo + hi) / 2;
        if check(mid, &s) {
            hi = mid;
        } else {
            lo = mid + 1
        }
    }
    lo
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();

    for _ in 0..t {
        let s = scanner.next::<String>();
        writeln!(out, "{}", solve(s)).ok();
    }
}
