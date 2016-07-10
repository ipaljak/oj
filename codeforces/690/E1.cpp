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

const int MAXN = 500;
const int K = 50;

int q, n, m, p[MAXN][MAXN];

ll sqr(ll x) {
	return x * x;
}

void solve() {
	scanf("%d %d",&n,&m);
	REP(i, n) REP(j, m) scanf("%d",&p[i][j]);

	ll score = 0;
	REP(i, m) score += sqr(p[(n-1)/2][i] - p[n/2][i]);

	lf ana = (lf)score / m;
	//TRACE(score _ m _ ana);
	if (score > K * K * m) puts("YES");
	else puts("NO");
}

int main() {
	scanf("%d",&q);
	while (q--) solve();
	return 0;
}
