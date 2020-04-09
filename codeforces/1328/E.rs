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

#[derive(Default, Clone)]
struct NodeData {
    dad: usize,
    depth: usize,
    discovery: usize,
    finish: usize,
}

fn dfs(node: usize, tick: &mut usize, v: &Vec<Vec<usize>>, node_data: &mut Vec<NodeData>) {
    node_data[node].discovery = *tick;
    *tick += 1;
    for nxt in &v[node] {
        if *nxt == node_data[node].dad {
            continue;
        }
        node_data[*nxt].dad = node;
        node_data[*nxt].depth = node_data[node].depth + 1;
        dfs(*nxt, tick, v, node_data);
    }
    node_data[node].finish = *tick;
}

fn query(mut q_vec: Vec<usize>, node_data: &Vec<NodeData>) -> bool {
    let mut pivot = 0;
    for node in &mut q_vec {
        if node_data[*node].depth > node_data[pivot].depth {
            pivot = *node;
        }
        if *node != 0 {
            *node = node_data[*node].dad;
        }
    }

    let mut ret = true;
    for node in &q_vec {
        ret &= node_data[*node].discovery <= node_data[pivot].discovery
            && node_data[*node].finish >= node_data[pivot].discovery;
    }

    ret
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scanner.next::<usize>();
    let m = scanner.next::<usize>();

    let mut v: Vec<Vec<usize>> = vec![Vec::new(); n];
    for _ in 0..n - 1 {
        let a = scanner.next::<usize>() - 1;
        let b = scanner.next::<usize>() - 1;
        v[a].push(b);
        v[b].push(a);
    }

    let mut node_data = vec![
        NodeData {
            dad: n,
            ..Default::default()
        };
        n
    ];

    let mut tick = 0;
    dfs(0, &mut tick, &v, &mut node_data);

    for _ in 0..m {
        let k = scanner.next::<usize>();
        let q_vec: Vec<usize> = (0..k).map(|_| scanner.next::<usize>() - 1).collect();
        if query(q_vec, &node_data) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
