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

fn inc_interval(l: usize, r: usize, val: i32, v: &mut Vec<i32>) -> () {
    if l > r {
        return ();
    }
    v[l] += val;
    v[r + 1] -= val;
}

fn solve(n: usize, k: usize, a: Vec<usize>) -> i32 {
    let mut pref = vec![0; 2*k + 2];
    for i in 0..n/2 {
        let x = a[i];
        let y = a[n - i - 1];
        let mid = x + y;
        let lo = cmp::max(2, mid - (cmp::max(x, y) - 1));
        let hi = cmp::min(2 * k, mid + k - cmp::min(x, y));
        //println!("{} {} {}", mid, lo, hi);
        inc_interval(2, lo - 1, 2, &mut pref);
        inc_interval(lo, mid - 1, 1, &mut pref);
        inc_interval(mid + 1, hi, 1, &mut pref);
        inc_interval(hi + 1, 2 * k, 2, &mut pref);
    }
    //println!("{:?}", pref);
    let mut sol = pref[2];
    let mut curr = pref[2];
    for i in 3..2*k + 1 {
        curr += pref[i];
        sol = cmp::min(sol, curr);
    }
    sol
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        let n = scanner.next::<usize>();
        let k = scanner.next::<usize>();
        let mut a = vec![];
        for _ in 0..n {
            a.push(scanner.next::<usize>());
        }
        writeln!(out, "{}", solve(n, k, a)).ok();
    }
}
