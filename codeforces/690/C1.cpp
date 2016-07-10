#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 1010;

int n, m, a, b, par[MAXN], cnt;

vector <int> v[MAXN];

bool bio[MAXN], cycle;

void dfs(int cvor) {
	bio[cvor] = 1;
	cnt++;

	REP(i, (int)v[cvor].size()) {
		int ncvor = v[cvor][i];
		if (bio[ncvor] && ncvor != par[cvor]) {
			cycle = 1;
			continue;
		}
		if (!bio[ncvor]) {
			par[ncvor] = cvor;
			dfs(ncvor);
		}
	}
}

int main() {
	memset(par, -1, sizeof par);
	scanf("%d %d",&n,&m);

	if (m != n - 1) {
		puts("no");
		return 0;
	}

	REP(i, m) {
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	if (cnt != n || cycle) puts("no");
	else puts("yes");

	return 0;
}
