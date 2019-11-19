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
llint a[MAXN], aa[MAXN];

llint sum = 0;
llint pref[MAXN];

llint solve_interval(int l, int r, llint k) {
  pref[l] = 0;
  llint p = 0, s = 0;
  for (int i = l + 1; i <= r; ++i) {
    pref[i] = pref[i - 1] + p + (a[i - 1] % k);
    p += a[i - 1] % k;
  }
  llint ss = 0;
  llint ret = pref[r];
  for (int i = r - 1; i >= l; --i) {
    ss += s + (a[i + 1] % k);
    s += a[i + 1] % k;
    ret = min(ret, pref[i] + ss);
  }
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
    a[i] = curr;
    if (curr == 0) {
      last = i;
    } else {
      last = i - 1;
    }
  }
  //TRACE(k _ ret);
  for (int i = 0; i < n; ++i) a[i] = aa[i];
  return ret;
}

bool prime(llint x) {
  for (llint i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    aa[i] = a[i];
    sum += (llint) a[i];
  }

  if (sum == 1) {
    printf("-1\n");
    return 0;
  }

  llint sol = check(sum);
  for (llint i = 2; i * i <= sum; ++i) {
    if (sum % i != 0) continue;
    if (prime(i))
      sol = min(sol, check(i));
    if (prime(sum / i))
      sol = min(sol, check(sum / i));
  }

  printf("%lld\n", sol);
  return 0;
}
