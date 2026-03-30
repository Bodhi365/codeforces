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
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  int mx = *max_element(a + 1, a + n + 1);
  int d = 0;
  rep(i, 1, n) d = gcd(d, mx - a[i]);
  if (!d) {
  	cout << 1 << endl;
  	return;
  }
  ll sum = 0;
  rep(i, 1, n) cnt[i] = 0;
  rep(i, 1, n) {
  	int x = (mx - a[i]) / d;
  	sum += x;
  	if (x <= n) cnt[x] = 1;
  }
  // 找 mex
  rep(i, 1, n) {
  	if (!cnt[i]) {
  		sum += i;
  		break;
  	}
  }
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