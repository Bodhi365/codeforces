#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll f[N], g[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  if (n == 1) {
  	cout << 1 << endl;
  	return;
  }
  f[0] = g[n + 1] = 0;
	for (int i = 2; i <= n; i += 2) {
		f[i] = max(a[i] - a[i - 1], f[i - 2]);
	}
	for (int i = n - 1; i >= 1; i -= 2) {
		g[i] = max(a[i + 1] - a[i], g[i + 2]);
	}
	if (n & 1) {
		ll ans = min(f[n - 1], g[2]);
		for (int i = 3; i < n; i += 2) {
			ans = min(ans, max(f[i - 1], g[i + 1]));
		}
		cout << ans << endl;
	} else {
		cout << g[1] << endl;
	}
	return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}