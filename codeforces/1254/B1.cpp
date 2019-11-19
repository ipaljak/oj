#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e6 + 10;
const llint INF = 1LL << 60;

int n;
int a[MAXN];

llint sum = 0;
llint pref[MAXN], suff[MAXN];

llint solve_interval(int l, int r, llint k) {
  llint ret = INF;
  pref[l] = 0;
  llint p = 0, s = 0;
  for (int i = l + 1; i <= r; ++i) {
    pref[i] = pref[i - 1] + p + (a[i - 1] % k);
    p += a[i - 1] % k;
  }
  suff[r] = 0;
  for (int i = r - 1; i >= l; --i) {
    suff[i] = suff[i + 1] + s + (a[i + 1] % k);
    s += a[i + 1] % k;
  }
  for (int i = l; i <= r; ++i) ret = min(ret, pref[i] + suff[i]);
  return ret;
}

llint check(llint k) {
  int last = -1;
  llint curr = 0;
  llint ret = 0;
  for (int i = 0; i < n; ++i) {
    curr += ((llint) a[i]) % k;
    if (curr < k) continue;
    a[i] -= curr % k;
    ret += solve_interval(last + 1, i, k);
    a[i] += curr % k;
    curr %= k;
    last = i;
  }
  return ret;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += (llint) a[i];
  }

  if (sum == 1) {
    printf("-1\n");
    return 0;
  }

  llint sol = check(sum);
  for (llint i = 2; i * i <= sum; ++i) {
    if (sum % i != 0) continue;
    sol = min(sol, check(i));
    sol = min(sol, check(sum / i));
  }

  printf("%lld\n", sol);
  return 0;
}
