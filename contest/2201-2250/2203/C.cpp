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
  ll l = 1, r = s / lowbit(m);
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid, s, m)) r = mid - 1;
    else l = mid + 1;
  }
  cout << l << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}