#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 6e5 + 5;

int n, m;
int a[N];
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int lcm(int x, int y) {
	int d = gcd(x, y);
	return x / d * y;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  int x = 1;
  rep(i, 2, n) {
  	int d = gcd(a[i], a[i - 1]);
  	int y = a[i - 1] / d;
  	x = lcm(x, y);
  }
  cout << x << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}