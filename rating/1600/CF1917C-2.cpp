#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k, m;
int a[N], b[N], c[N];

void solve() {
  cin >> n >> k >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, k) cin >> b[i];
  int ans = (m - 1) / 2;
  rep(i, 1, min(m, n * 2 + 1)) {
    int cnt = 0;
    rep(j, 1, n) if (a[j] == j) cnt++;
    ans = max(ans, (m - i) / 2 + cnt);
    int x = b[(i - 1) % k + 1];
    rep(j, 1, x) a[j]++;
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