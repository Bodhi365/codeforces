#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 105;

int n, m;
char a[N][N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  int ans = 0;
  rep(x, 1, n - 1) rep(y, 1, m - 1) {
    int cnt = 0;
    rep(dx, 0, 1) rep(dy, 0, 1) {
      cnt += a[x + dx][y + dy] - '0';
    }
    if (cnt == 3) ans++;
  }
  cout << (ans ? "NO" : "YES") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}