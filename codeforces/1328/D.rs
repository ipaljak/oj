use std::io::{stdin, stdout, BufWriter, Write};
use std::collections::HashSet;
use std::iter::FromIterator;

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

fn solve(v: Vec<i32>) -> (usize, Vec<i32>) {
    let s: HashSet<i32> = HashSet::from_iter(v.clone());
    if s.len() == 1 {
        return (1, vec![1; v.len()]);
    }

    if v.len() % 2 == 0 {
        return (2, (0..v.len()).map(|x| (x as i32) % 2 + 1).collect())
    }

    let mut adj_same_id: i32 = -1;
    for i in 0..v.len() {
        if v[i] == v[(i + 1) % v.len()] {
            adj_same_id = i as i32;
        }
    }

    if adj_same_id == -1 {
        let mut ret : Vec<i32> = (0..v.len()).map(|x| (x as i32) % 2 + 1).collect();
        *ret.last_mut().unwrap() = 3;
        return (3, ret);
    }

    let mut ret = Vec::new();
    for i in 0..v.len() {
        if i as i32 <= adj_same_id {
            ret.push((i % 2 + 1) as i32);
        } else {
            ret.push(((i + 1) % 2 + 1) as i32);
        }
    }

    (2, ret)
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scanner.next::<usize>();
    for _ in 0..t {
        let n = scanner.next::<usize>();
        let v: Vec<i32> = (0..n).map(|_| scanner.next()).collect();
        let (n, sol) = solve(v);
        writeln!(out, "{}", n).ok();
        for col in sol {
            write!(out, "{} ", col).ok();
        }
        writeln!(out, "").ok();
    }
}
