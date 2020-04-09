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

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        let n = scanner.next::<usize>();
        let a: Vec<usize> = (0..n).map(|_| scanner.next()).collect();
        let mut has_palin = false;
        for i in 0..n {
            for j in i + 2..n {
                has_palin |= a[i] == a[j];
            }
        }
        writeln!(out, "{}", if has_palin { "YES" } else { "NO" }).ok();
    }
}
