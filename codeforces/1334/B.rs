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
        let x = scanner.next::<i64>();
        let mut v: Vec<i64> = (0..n).map(|_| scanner.next()).collect();
        v.sort();
        v.reverse();
        let mut sum = 0;
        let mut sol = 0;
        for i in 0..n {
            sum += v[i];
            if sum >= ((i + 1) as i64) * x {
                sol = i + 1;
            }
        }
        writeln!(out, "{}", sol).ok();
    }
}
