#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e6 + 5;

int n, m, mx;
int a[N], b[N], c[N];

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
  cin >> n >> m;
  mx = n + m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  rep(i, 1, mx) c[i] = 0;
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  // sieve
  rep(i, 1, n) {
    int p = a[i];
    if (!c[p]) {
      for (int j = p; j <= mx; j += p) c[j] = 1;
    }
  }
  ll lcm = a[1];
  rep(i, 1, n) {
    ll d = gcd(lcm, a[i]);
    lcm = lcm / d * a[i];
    if (lcm > mx) break;
  }
  int x = 0, y = 0, z = 0;
  rep(i, 1, m) {
    int p = b[i];
    if (c[p] && p % lcm == 0) y++;
    else if (c[p]) x++;
    else z++;
  }
  y += (x + 1) / 2, z += x / 2;
  if (y > z) cout << "Alice" << endl;
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