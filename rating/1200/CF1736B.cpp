#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N];
int b[N];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool check() {
	rep(i, 1, n) if (gcd(b[i], b[i + 1]) != a[i]) return false;
	return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  b[1] = a[1], b[n + 1] = a[n];
  rep(i, 2, n) b[i] = lcm(a[i - 1], a[i]);
  cout << (check() ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}