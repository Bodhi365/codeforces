#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;
const int INF = 1e9;

int n, m;
int a[6] = {0, 1, 3, 6, 10, 15};
int dp[105];
void init() {
	rep(i, 1, 100) dp[i] = INF;
	rep(i, 1, 5) {
		rep(j, a[i], 100) dp[j] = min(dp[j], dp[j - a[i]] + 1);
	}
}
void solve() {
  cin >> n;
  if (n <= 100) {
  	cout << dp[n] << endl;
  	return;
  }
  int r = n % 15 + 15;
  cout << n / 15 - 1 + dp[r] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}