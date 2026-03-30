#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];
int c[N];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	int d = gcd(a, b);
	return a / d * b;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) {
  	int x = 1, y = 1;
  	if (i > 1) x = gcd(a[i], a[i - 1]);
  	if (i < n) y = gcd(a[i], a[i + 1]);
  	c[i] = lcm(x, y);
  }
  int cnt = 0;
  rep(i, 1, n) if (c[i] != a[i]) cnt++;
  cout << cnt << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}