#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;

ll lowbit(ll x) { return x & -x; }
bool check(ll x, ll s, ll m) {
  per(i, 59, 0) {
    if ((m >> i) & 1) {
      ll v = 1ll << i;
      ll now = min(s / v, x);
      s -= now * v;
    }
  }
  return !s;
}
void solve() {
  ll s, m;
  cin >> s >> m;
  if (lowbit(s) < lowbit(m)) {
    cout << -1 << endl;
    return;
  }
  ll ans = 0;
  rep(i, 1, 60) {
    ll mask = (1ll << i) - 1;
    ll x = (s & mask);
    ll y = (m & mask);
    if (!y) continue;
    ll z = (x + y - 1) / y;
    ans = max(ans, z);
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}