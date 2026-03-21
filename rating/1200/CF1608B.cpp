#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x, y;
int a[N];

void solve() {
  cin >> n >> x >> y;
  if (abs(x - y) >= 2 || x + y > n - 2) {
    cout << -1 << endl;
    return;
  }
  bool fmn = x >= y;
  if (fmn) y++;
  else x++;
  int mn = 1, mx = n;
  for (int i = 1; i <= n; i++) {
    if (fmn) {
      a[i] = mn++;
      if (y) y--;
    } else {
      a[i] = mx--;
      if (x) x--;
    }
    if (x || y) fmn = !fmn;
  }
  rep(i, 1, n) cout << a[i] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}