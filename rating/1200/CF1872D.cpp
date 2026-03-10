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
ll C(ll n) {
  return n * (n + 1) / 2;
}
void solve() {
  cin >> n >> x >> y;
  int z = gcd(x, y);
  int c1 = n / x, c2 = n / y, c3 = n / x / (y / z);
  c1 -= c3, c2 -= c3;
  ll sum = C(n) - C(n - c1) - C(c2);
  cout << sum << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}