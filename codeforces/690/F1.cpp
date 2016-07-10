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

const int MAXN = 10100;

int n, deg[MAXN], a, b;

int main() {
	scanf("%d",&n);
	REP(i, n - 1) {
		scanf("%d %d",&a,&b);
		deg[a]++;
		deg[b]++;
	}

	ll sol = 0;
	FOR(i, 1, n + 1) 
		sol += (ll)deg[i] * (deg[i] - 1) / 2;

	printf("%lld\n",sol);
	return 0;
}
