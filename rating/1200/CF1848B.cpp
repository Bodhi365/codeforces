#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k;

void solve() {
  cin >> n >> k;
  vector<vector<int>> a(k + 1, vector<int>());
  rep(i, 1, k) a[i].push_back(0);
  rep(i, 1, n) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  rep(i, 1, k) a[i].push_back(n + 1);
  int ans = n;
  rep(i, 1, k) {
    if (a[i].size() <= 2) continue;
    int len = a[i].size();
    int mn = 0, mx = 0;
    rep(j, 1, len - 1) {
      int now = a[i][j] - a[i][j - 1] - 1;
      if (now > mn) swap(mn, now);
      if (mn > mx) swap(mx, mn);
    }
    ans = min(ans, max(mn, mx / 2));
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