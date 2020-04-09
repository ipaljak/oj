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

fn solve(n: usize, mut k: usize) -> String {
    let mut ret: Vec<char> = "a".repeat(n).chars().collect();
    for i in (0..n - 1).rev() {
        if k <= n - i - 1 {
            ret[i] = 'b';
            ret[n - k] = 'b';
            break;
        } else {
            k -= n - i - 1;
        }
    }
    ret.into_iter().collect()
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        let n = scanner.next::<usize>();
        let k = scanner.next::<usize>();
        writeln!(out, "{}", solve(n, k)).ok();
    }
}


