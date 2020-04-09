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

fn solve(x: String) -> (String, String) {
    let mut a = String::new();
    let mut b = String::new();
    let mut flag = false;
    for c in x.chars() {
        match c {
            '0' => {
                a.push('0');
                b.push('0');
            },
            '1' => {
                if !flag {
                    a.push('1');
                    b.push('0');
                    flag = true;
                } else {
                    a.push('0');
                    b.push('1');
                }
            },
            '2' => {
                if !flag {
                    a.push('1');
                    b.push('1');
                } else {
                    a.push('0');
                    b.push('2');
                }
            },
            _   => ()
        }
    }
    (a, b)
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        scanner.next::<usize>();
        let x = scanner.next::<String>();
        let (a, b) = solve(x);
        writeln!(out, "{}\n{}", a, b).ok();
    }
}
