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

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  ll ans = 0;
  rep(i, 1, n) {
  	for (ll k = max(a[i], (i * 2 + a[i]) / a[i] * a[i]); k <= i + n; k += a[i]) {
  		int j = k - i;
  		if (a[i] * a[j] == k) ans++;
  	}
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}