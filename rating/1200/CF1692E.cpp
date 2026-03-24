#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, s;
int a[N];

void solve() {
  cin >> n >> s;
  rep(i, 1, n) cin >> a[i];
  int sum = accumulate(a + 1, a + n + 1, 0);
  if (sum < s) {
  	cout << -1 << endl;
  	return;
  }
  int ans = 0;
  for (int l = 1, r = 1, cnt = 0; r <= n; r++) {
  	cnt += a[r];
  	while (cnt > s) cnt -= a[l++];
  	if (cnt == s) ans = max(ans, r + 1 - l);
  }
  cout << n - ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}