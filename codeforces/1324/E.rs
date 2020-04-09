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

struct Params {
    n: usize,
    h: usize,
    l: usize,
    r: usize,
    a: Vec<usize>,
}

fn dp(i: usize, hh: usize, params: &Params, memo: &mut Vec<Vec<i32>>) -> usize {
    if memo[i][hh] != -1 {
        return memo[i][hh] as usize;
    }
    if i == params.n {
        memo[i][hh] = 0;
        return memo[i][hh] as usize;
    }

    let t1 = (hh + params.a[i] - 1) % params.h;
    let t2 = (hh + params.a[i]) % params.h;

    let d1 = if params.l <= t1 && t1 <= params.r {1} else {0};
    let d2 = if params.l <= t2 && t2 <= params.r {1} else {0};

    memo[i][hh] = cmp::max(d1 + dp(i + 1, t1, params, memo),
                           d2 + dp(i + 1, t2, params, memo)) as i32;
    return memo[i][hh] as usize;
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scanner.next::<usize>();
    let h = scanner.next::<usize>();
    let l = scanner.next::<usize>();
    let r = scanner.next::<usize>();
    let a: Vec<usize> = (0..n).map(|_| scanner.next()).collect();

    let mut memo: Vec<Vec<i32>> = vec![vec![-1; h]; n + 1];
    writeln!(out, "{}", dp(0, 0, &Params{n, h, l, r, a}, &mut memo)).ok();
}
