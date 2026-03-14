#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll a, b, m, k;

void solve() {
  cin >> m >> k >> a >> b;
  ll ans = 0;
  ll r = m % k;
  if (a < r) ans += r - a, a = 0;
  else a -= r;
  ans += max(0ll, m / k - b - a / k);
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