#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e6 + 5;

int n, m;
int a[N], b[N], c[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  rep(i, 1, n + m) c[i] = 0;
  int tot = 0;
  rep(i, 1, n) {
    if (!c[a[i]]) c[a[i]] = 1, tot++;
  }
  int x = 0, y = 0, z = 0;
  rep(i, 1, m) {
    int now = b[i];
    int d = 0, nd = 0;
    rep(j, 1, n + m) {
      if (1ll * j * j > now) break;
      if (d && nd) break;
      if (now % j) {
        if (c[j]) nd = 1;
        continue;
      }
      if (c[j]) d++;
      int k = now / j;
      if (k != j && c[k]) d++; 
    }
    nd = tot - d;
    if (d && nd) x++;
    else if (d) y++;
    else z++;
  }
  y += (x + 1) / 2, z += x / 2;
  if (y > z) cout << "Alice";
  else cout << "Bob";
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