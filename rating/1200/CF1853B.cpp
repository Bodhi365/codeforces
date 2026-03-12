#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;
const int MX = 2e5;

int n, k;
int a[N], b[N], num;

ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
ll calc(ll a, ll b, ll c) {
  // a * x + b * y == c
  ll x, y;
  ll d = extgcd(a, b, x, y);
  if (c % d) return 0;
  a /= d, b /= d, c /= d;
  x *= c, y *= c;
  x = (x % b + b) % b;
  ll mx = c / (a + b);
  ll ans = max(0ll, (mx - x + b) / b);
  return ans;
}
void solve() {
  cin >> n >> k;
  if (k > num) {
    if (n == 0) cout << 1 << endl;
    else cout << 0 << endl;
    return;
  }
  cout << calc(a[k], b[k], n) << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  a[1] = 1, a[2] = 0;
  b[1] = 0, b[2] = 1;
  num = 2;
  while (a[num] <= MX || b[num] <= MX) {
    ++num;
    a[num] = a[num - 1] + a[num - 2];
    b[num] = b[num - 1] + b[num - 2];
  }
  num--;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}