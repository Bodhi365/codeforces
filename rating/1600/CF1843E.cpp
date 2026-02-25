#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, q;
int a[N], b[N], c[N];
int d[N];

bool check(int k) {
  rep(i, 1, n) d[i] = 0;
  rep(i, 1, k) d[c[i]] = 1;
  rep(i, 1, n) d[i] += d[i - 1];
  rep(i, 1, m) {
    int len = b[i] + 1 - a[i];
    int cnt = d[b[i]] - d[a[i] - 1];
    if (cnt * 2 > len) return true;
  }
  return false;
}
void solve() {
  cin >> n >> m;
  rep(i, 1, m) cin >> a[i] >> b[i];
  cin >> q;
  rep(i, 1, q) cin >> c[i];
  int l = 1, r = q;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid - 1;
    else l = mid + 1;
  }
  if (l <= q) cout << l << endl;
  else cout << -1 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}