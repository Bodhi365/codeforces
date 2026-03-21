#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1005;

int n, m;
char g[N][N];
int t[5];
void solve() {
  cin >> n;
  rep(i, 1, n) rep(j, 1, n) cin >> g[i][j];
  int ans = 0;
  rep(i, 1, n / 2) rep(j, 1, n / 2) {
    int x = i, y = j;
    for (int k = 1; k <= 4; k++) {
      t[k] = g[x][y];
      int nx = y, ny = n + 1 - x;
      x = nx, y = ny;
    }
    sort(t + 1, t + 5);
    for (int k = 1; k <= 4; k++) ans += t[4] - t[k];
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