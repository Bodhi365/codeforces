#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m;
ll a[N], b[N], ans[N];
struct Bit {
  int n;
  vector<ll> a;
  void init(int _n) {
    n = _n;
    a = vector<ll>(n + 1, 0);
  }
  int lowbit(int x) { return x & -x; }
  void add(int x, ll d) {
    for (int i = x; i <= n; i += lowbit(i)) a[i] += d;
  }
  ll query(int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += a[i];
    return res;
  }
} sum, cnt;
set<int> ids;

ll qpow(ll b, ll p) {
  ll res = 1;
  b %= MOD;
  while (p) {
    if (p & 1) res = res * b % MOD;
    b = b * b % MOD;
    p >>= 1;
  }
  return res;
}
ll left(int p) {
  if (p <= 1) return 0;
  ll x = cnt.query(p);
  ll y = sum.query(p);
  return x * b[p] - y;
}
ll right(int p) {
  if (p >= n) return 0;
  ll x = cnt.query(n) - cnt.query(p - 1);
  ll y = sum.query(n) - sum.query(p - 1);
  return y - x * b[p];
}
ll get_min() {
  int l = 2, r = n - 1;
  // 找到 第一个 sum_left >= sum_right 的位置
  while (l <= r) {
    int mid = (l + r) >> 1;
    ll f1 = left(mid);
    ll f2 = right(mid);
    if (f1 >= f2) r = mid - 1;
    else l = mid + 1;
  }
  vector<ll> t;
  auto it = ids.lower_bound(l);
  t.push_back(right(*it));
  t.push_back(right(*(++it)));
  it--, it--;
  t.push_back(left(*it));
  t.push_back(left(*(--it)));
  sort(t.begin(), t.end());
  return t[2];
}

void solve() {
  cin >> n;
  cnt.init(n), sum.init(n);
  ids.insert(0), ids.insert(-1), ids.insert(n + 1), ids.insert(n + 2);
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) b[i] = a[i];
  sort(b + 1, b + n + 1);
  rep(i, 1, n) {
    int p = lower_bound(b + 1, b + n + 1, a[i]) - b;
    cnt.add(p, 1);
    sum.add(p, a[i]);
    ids.insert(p);
    if (i <= 3) continue;
    ans[i] = get_min();
  }
  rep(i, 3, n) cout << ans[i] % MOD * qpow(i - 2, MOD - 2) % MOD << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}