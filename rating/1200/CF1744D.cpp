#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], c[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) {
    b[i] = 0;
    while (!(a[i] & 1)) b[i]++, a[i] >>= 1;
  }
  int cnt = accumulate(b + 1, b + n + 1, 0);
  if (cnt >= n) {
    cout << 0 << endl;
    return;
  }
  int k = 0;
  c[0] = n;
  while (c[k] > 1) {
    c[k + 1] = c[k] / 2;
    k++;
  }
  rep(i, 1, k - 1) c[i] -= c[i + 1];
  int ans = 0;
  per(i, k, 1) {
    rep(j, 1, c[i]) {
      cnt += i, ans++;
      if (cnt >= n) {
        cout << ans << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}