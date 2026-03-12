#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;

void solve() {
  cin >> n >> m;
  vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));
  rep(i, 1, n) rep(j, 1, m) cin >> a[j][i];
  ll ans = 0;
  rep(i, 1, m) {
    sort(a[i].begin() + 1, a[i].end());
    ll sum = 0;
    rep(j, 1, n) {
      ll now = 1ll * (j - 1) * a[i][j] - sum;
      sum += a[i][j];
      ans += now;
    }
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