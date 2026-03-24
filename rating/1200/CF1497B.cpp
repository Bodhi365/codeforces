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
int cnt[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 0, m - 1) cnt[i] = 0;
  rep(i, 1, n) cnt[a[i] % m]++;
  ll ans = (cnt[0] != 0) + (m % 2 == 0 && cnt[m / 2] ? 1 : 0);
  rep(i, 1, (m - 1) / 2) {
  	int j = m - i;
  	int x = cnt[i], y = cnt[j];
  	if (!x && !y) continue;
  	ans += max(1, abs(x - y));
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