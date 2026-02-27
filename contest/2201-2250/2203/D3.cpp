#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e6 + 5;

int n, m, mx;
int a[N], b[N], c[N], d[N];

void solve() {
  cin >> n >> m;
  mx = n + m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  rep(i, 1, mx) c[i] = 0, d[i] = 0;
  rep(i, 1, n) c[a[i]]++;
  rep(i, 1, mx) {
    if (!c[i]) continue;
    for (int j = i; j <= mx; j += i) d[j] += c[i];
  }
  int x = 0, y = 0, z = 0;
  rep(i, 1, m) {
    int cnt = d[b[i]];
    if (cnt == n) x++;
    else if (cnt == 0) y++;
    else z++;
  }
  x += (z + 1) / 2, y += z / 2;
  if (x > y) cout << "Alice" << endl;
  else cout << "Bob" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}