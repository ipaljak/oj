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
        let mut p = 0;
        let mut c = 0;
        let mut ok = true;
        for _ in 0..n {
            let pi = scanner.next::<usize>();
            let ci = scanner.next::<usize>();
            if pi >= p && ci >= c && pi - p >= ci - c {
                p = pi;
                c = ci;
            } else {
                ok = false;
            }
        }
        writeln!(out, "{}", if ok {"YES"} else {"NO"}).ok();
    }
}
