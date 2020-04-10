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

fn solve(scanner: &mut Scanner) -> i64 {
    let n = scanner.next::<usize>();
    let mut a: Vec<i64> = Vec::new();
    let mut b: Vec<i64> = Vec::new();
    let mut sol: i64 = 0;
    for _ in 0..n {
        a.push(scanner.next::<i64>());
        b.push(scanner.next::<i64>());
    }
    let mut savings: i64 = 1e13 as i64;
    for i in 0..n {
        sol += std::cmp::max(0, a[i] - b[(i + n - 1) % n]);
        savings = std::cmp::min(savings, std::cmp::min(b[(i + n - 1) % n], a[i]));
    }
    //println!("{} {}", sol, savings);
    sol + savings
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();

    for _ in 0..t {
        writeln!(out, "{}", solve(&mut scanner)).ok();
    }
}
