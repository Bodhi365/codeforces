#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, x;
ll a[N], b[N], c[N];

void solve() {
  cin >> n >> x;
  rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
  ll sum = 0, mx = 0;
  rep(i, 1, n) sum += a[i] * (b[i] - 1);
  rep(i, 1, n) mx = max(mx, a[i] * b[i] - c[i]);
  ll ans = -1;
  if (sum >= x) ans = 0;
  else if (mx > 0) ans = (x - sum + mx - 1) / mx;
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