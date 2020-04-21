use std::io::{stdin, stdout, BufWriter, Write};
use std::cmp;

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

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        let n = scanner.next::<usize>();
        let mut sol: i64 = 0;
        let mut curr = scanner.next::<i64>();
        for _ in 0..n-1 {
            let nxt = scanner.next::<i64>();
            if curr * nxt > 0 {
                curr = cmp::max(curr, nxt);
            } else {
                sol += curr;
                curr = nxt;
            }
        }
        sol += curr;
        writeln!(out, "{}", sol).ok();
    }
}
