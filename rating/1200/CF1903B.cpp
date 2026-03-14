#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1005;

int n, a[N], b[N][N];

bool check() {
  rep(i, 1, n) rep(j, 1, n) {
    if (i == j) continue;
    if ((a[i] | a[j]) != b[i][j]) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n) rep(j, 1, n) cin >> b[i][j];
  if (n == 1) {
    cout << "YES" << endl;
    cout << 0 << endl;
    return;
  }
  rep(i, 1, n) a[i] = 0;
  rep(k, 0, 29) {
    rep(i, 1, n) {
      int cnt = 0;
      rep(j, 1, n) if (b[i][j] >> k & 1) cnt++;
      if (cnt == n - 1) a[i] |= 1 << k;
    }
  }
  if (!check())
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}