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
        if n % 4 != 0 {
            writeln!(out, "NO").ok();
            continue;
        }
        let mut even = vec![2, 4];
        let mut odd = vec![1, 5];
        for c in 1..n/4 {
            even.push(even[0] + 6 * (c + 1));
            even.push(even[1] + 6 * (c + 1));
            odd.push(odd[0] + 6 * (c + 1));
            odd.push(odd[1] + 6 * (c + 1));
        }
        writeln!(out, "YES").ok();
        for x in even {
            write!(out, "{} ", x).ok();
        }
        for x in odd {
            write!(out, "{} ", x).ok();
        }
        writeln!(out, "").ok();
    }
}
