#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, t;
struct Node {
  ll s, t, id;
  bool operator<(const Node& o) const {
    if (s != o.s) return s > o.s;
    else if (t != o.t) return t < o.t;
    else return id < o.id;
  }
};
void solve() {
  cin >> n >> m >> t;
  vector<vector<int>> a(n + 1, vector<int>(m));
  vector<Node> b(n + 1);
  rep(i, 1, n) rep(j, 0, m - 1) cin >> a[i][j];
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  rep(i, 1, n) {
    sort(a[i].begin(), a[i].end());
    ll sum = 0;
    b[i].s = 0, b[i].t = 0, b[i].id = i;
    rep(j, 0, m - 1) {
      if (sum + a[i][j] > t) break;
      sum += a[i][j];
      b[i].s++;
      b[i].t += sum;
    }
  }
  sort(b.begin() + 1, b.end());
  int ans = 1;
  rep(i, 1, n) if (b[i].id == 1) ans = i;
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