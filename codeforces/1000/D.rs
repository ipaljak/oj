use std::io::stdin;

const MOD: i32 = 998244353;

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
    if a + b >= MOD { return a + b - MOD; }
    if a + b < 0 { return a + b + MOD; }
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
    let mut a = Vec::new();
    for _ in 0..n {
        let x = scanner.next::<i32>();
        a.push(x);
    }

    let mut fact: Vec<i32> = vec![1; n];
    for i in 1..n {
        fact[i] = mul(i as i32, fact[i - 1]);
    }

    let mut sol = 0;
    let mut dp: Vec<i32> = vec![0; n + 1];
    dp[n as usize] = 1;
    for i in (0..n).rev() {
        if a[i] <= 0 { continue; }
        for j in (i + (a[i] as usize) + 1)..(n + 1) {
            dp[i] = add(dp[i], mul(choose(j - i - 1, a[i] as usize, &fact), dp[j]));
        }
        sol = add(sol, dp[i]);
    }

    println!("{}", sol);
}
