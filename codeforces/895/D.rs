use std::io::stdin;

const MOD: i32 = 1000000007;

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

fn id(s: &String, mut cnt: Vec<i32>, fact: &Vec<i32>) -> i32 {
    let mut ret = 1;
    let mut rest = s.len();
    for chr in s.as_bytes() {
        let mut div = 1;
        for x in &cnt {
            div = mul(div, fact[*x as usize]);
        }
        let invdiv = inv(div);

        let cid = *chr as usize - 'a' as usize;
        rest -= 1;
        for i in 0..cid {
            if cnt[i] == 0 {
               continue;
            }
            ret = add(ret, mul(mul(cnt[i], fact[rest]), invdiv));
        }

        cnt[cid] -= 1;
    }

    ret
}

fn get_pref(mut cnt: Vec<i32>, s: &String) -> usize {
    let mut pref: usize = 0;
    let s_bytes = s.as_bytes();
    for i in 0..(s_bytes.len() - 1) {
        let cid = s_bytes[i] as usize - 'a' as usize;
        if cnt[cid] == 0 {
            break;
        }

        cnt[cid] -= 1;
        let nid = s_bytes[i + 1] as usize - 'a' as usize;
        let mut flag = false;
        for j in 0..nid {
            flag |= cnt[j] > 0;
        }

        if flag {
            pref = i + 1;
        }
    }
    pref
}

fn upper_bound(mut cnt: Vec<i32>, s: &String) -> String {
    let pref = get_pref(cnt.clone(), s);
    let mut ret = s.as_str()[..pref].to_string();
    for chr in ret.as_bytes() {
        cnt[*chr as usize - 'a' as usize] -= 1;
    }

    let mut nid = (s.as_bytes()[pref] as usize - 'a' as usize) - 1;
    while cnt[nid] == 0 {
        nid -= 1;
    }

    cnt[nid] -= 1;
    ret.push(('a' as u8 + nid as u8) as char);

    for i in (0..26).rev() {
        for _ in 0..cnt[i] {
            let chr = ('a' as u8 + i as u8) as char;
            ret.push(chr);
        }
    }

    ret
}

fn main() {
    let mut scanner = Scanner::default();
    let a = scanner.next::<String>();
    let b = scanner.next::<String>();
    let n = a.len();

    let mut cnt = vec![0; 26];
    for chr in a.chars() {
        cnt[chr as usize - 'a' as usize] += 1;
    }

    let mut fact = vec![1; n + 1];
    for i in 1..n {
        fact[i] = mul(i as i32, fact[i - 1]);
    }

    let a_max = upper_bound(cnt.clone(), &b);

    let id1 = id(&a, cnt.clone(), &fact);
    let id2 = id(&a_max, cnt.clone(), &fact);

    println!("{}", add(id2, -id1));
}
