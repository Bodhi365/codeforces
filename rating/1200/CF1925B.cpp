#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, x;

void solve() {
  cin >> x >> n;
  ll ans = 0;
  for (ll i = 1; i * i <= x; i++) {
    if (x % i) continue;
    ll j = x / i;
    if (i >= n) ans = max(ans, j);
    if (j >= n) ans = max(ans, i);
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