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

fn solve(scanner: &mut Scanner) -> Vec<i64> {
    let n = scanner.next::<i64>();
    let l = scanner.next::<i64>();
    let r = scanner.next::<i64>();
    let mut a: i64 = 1;
    let mut b: i64 = 2;
    let mut curr = 0;
    for i in (0..n).rev() {
        if curr + 2 * i >= l {
            a = n - i;
            b = a + 1 + (l - curr - 1) / 2;
            //println!("{} {} {}", a, l, curr);
            break;
        } else {
            curr += 2 * i;
        }
    }
    //println!("{} {}", a, b);
    let mut sol: Vec<i64> = Vec::new();
    for i in l..r+1 {
        if i % 2 == 1 {
            sol.push(a);
        } else {
            sol.push(b);
            b = b + 1;
        }
        if *sol.last().unwrap() == n {
            a = a + 1;
            b = a + 1;
        }
    }
    if r == n * (n - 1) + 1 {
        *sol.last_mut().unwrap() = 1;
    }
    sol
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();

    for _ in 0..t {
        let sol = solve(&mut scanner);
        for x in sol {
            write!(out, "{} ", x).ok();
        }
        writeln!(out, "").ok();
    }
}
