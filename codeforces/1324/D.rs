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

    let n = scanner.next::<usize>();
    let a: Vec<i32> = (0..n).map(|_| scanner.next()).collect();
    let b: Vec<i32> = (0..n).map(|_| scanner.next()).collect();

    let mut ab: Vec<i32> = a.iter().zip(b.iter()).map(|(ai, bi)| ai - bi).collect();
    let mut ba: Vec<i32> = a.iter().zip(b.iter()).map(|(ai, bi)| bi - ai).collect();

    ab.sort();
    ba.sort();

    let mut ba_ptr = 0;
    let mut pairs: i64 = 0;
    for (i, val) in ab.iter().enumerate() {
        while ba_ptr < n && *val > ba[ba_ptr] {
            ba_ptr += 1;
        }
        pairs += ba_ptr as i64;
        if a[i] > b[i] { pairs -= 1; }
    }

    writeln!(out, "{}", pairs / 2).ok();
}
