#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 105;

int n, k;
int a[N];

void solve() {
  cin >> n >> k;
  if ((n & 1) == (k & 1)) {
    if (n < k) {
      cout << "NO" << endl;
      return;
    }
    int x = (n - k) / 2 / k;
    int y = (n - k) / 2 % k;
    rep(i, 1, k) {
      a[i] = 1 + x * 2;
      if (i <= y) a[i] += 2;
    }
    cout << "YES" << endl;
    rep(i, 1, k) cout << a[i] << ' ';
    cout << endl;
  } else if (n & 1) {
    cout << "NO" << endl;
  } else {
    if (n < 2 * k) {
      cout << "NO" << endl;
      return;
    }
    int x = n / 2 / k;
    int y = n / 2 % k;
    rep(i, 1, k) {
      a[i] = x * 2;
      if (i <= y) a[i] += 2;
    }
    cout << "YES" << endl;
    rep(i, 1, k) cout << a[i] << ' ';
    cout << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}