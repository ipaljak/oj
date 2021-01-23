use std::collections::HashMap;
use std::io::stdin;

const MOD: i32 = 998244353;
const MAX: usize = 300010;

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

fn add(a: i32, b: i32) -> i32 {
    if a + b >= MOD {
        return a + b - MOD;
    }
    if a + b < 0 {
        return a + b + MOD;
    }
    a + b
}

fn mul(a: i32, b: i32) -> i32 {
    ((a as i64) * (b as i64) % (MOD as i64)) as i32
}

fn pow(mut b: i32, mut e: i32) -> i32 {
    let mut ret = 1;
    while e > 0 {
        if e & 1 != 0 {
            ret = mul(ret, b);
            e -= 1;
        }
        b = mul(b, b);
        e /= 2;
    }
    ret
}

fn inv(x: i32) -> i32 {
    pow(x, MOD - 2)
}

fn choose(n: usize, k: usize, fact: &Vec<i32>) -> i32 {
    mul(fact[n], inv(mul(fact[k], fact[n - k])))
}

fn main() {
    let mut scanner = Scanner::default();
    let n = scanner.next::<usize>();

    let mut cnt: HashMap<i32, i32> = HashMap::new();
    let mut a = Vec::new();
    for _ in 0..n {
        let x = scanner.next::<i32>();
        a.push(x);
        match cnt.get_mut(&x) {
            None => {
                cnt.insert(x, 1);
            }
            Some(y) => {
                *y += 1;
            }
        }
    }

    let mut fact: Vec<i32> = vec![1; MAX];
    for i in 1..MAX {
        fact[i] = mul(i as i32, fact[i - 1]);
    }

    let mut dp = vec![vec![0; 8]; MAX];
    let mut sol: i32 = -1;
    for i in (1..MAX).rev() {
        for j in 1..8 {
            let mut c = 0;
            for pi in (i..MAX).step_by(i) {
                c += match cnt.get(&(pi as i32)) {
                    None => 0,
                    Some(x) => *x,
                }
            }
            if c >= j as i32 {
                dp[i][j] = choose(c as usize, j, &fact);
                for pi in ((i + i)..MAX).step_by(i) {
                    dp[i][j] = add(dp[i][j], -dp[pi as usize][j]);
                }
                if sol == -1 && i == 1 && dp[i][j] != 0 {
                    sol = j as i32;
                }
            }
        }
    }

    println!("{}", sol);
}
