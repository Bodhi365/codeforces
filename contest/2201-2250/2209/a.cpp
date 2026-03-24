#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, c, k;
ll a[N];

void solve() {
  cin >> n >> c >> k;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  rep(i, 1, n) {
    if (a[i] > c) break;
    ll x = min(k, c - a[i]);
    k -= x;
    c += a[i] + x;
  }
  cout << c << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}