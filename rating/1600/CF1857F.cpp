#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> m;
  while (m--) {
    ll x, y;
    cin >> x >> y;
    ll delta = x * x - 4 * y;
    if (delta < 0) {
      cout << 0 << ' ';
      continue;
    }
    ll r = round(sqrt(delta));
    if (r * r != delta || ((x - r) & 1)) {
      cout << 0 << ' ';
      continue;
    }
    ll x1 = (x - r) / 2, x2 = (x + r) / 2;
    ll cnt1 = upper_bound(a + 1, a + n + 1, x1) - lower_bound(a + 1, a + n + 1, x1);
    ll cnt2 = upper_bound(a + 1, a + n + 1, x2) - lower_bound(a + 1, a + n + 1, x2);
    ll ans = x1 != x2 ? cnt1 * cnt2 : cnt1 * (cnt1 - 1) / 2;
    cout << ans << ' ';
  }
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}