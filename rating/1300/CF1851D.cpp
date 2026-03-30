#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll b[N];
int cnt[N << 1];
bool check() {
	rep(i, 1, n) if (cnt[i] != 1) return false;
	return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n - 1) cin >> b[i];
  rep(i, 1, n) cnt[i] = 0;
  rep(i, 1, n - 1) {
  	ll d = b[i] - b[i - 1];
  	if (d <= 0) {
  		cout << "NO" << endl;
  		return;
  	}
  	if (d <= n) cnt[d]++;
  }
  ll sum = 1ll * n * (n + 1) / 2;
  if (sum != b[n - 1]) {
  	ll d = sum - b[n - 1];
  	if (d > n || d < 0) {
  		cout << "NO" << endl;
  		return;
  	}
  	cnt[d]++;
  	cout << (check() ? "YES" : "NO") << endl;
  	return;
  }
  ll num = 0;
  rep(i, 1, n) if (!cnt[i]) num++;
  cout << (num == 2 ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}