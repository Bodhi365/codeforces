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
string s;

int dp[1005][1005][2]; // tot, single, reversed

void init(int n) {
	rep(x, 1, n) {
		rep(y, 0, x) {
			dp[x][y][0] = INF;
			if (y) dp[x][y][0] = min(dp[x][y][0], x - dp[x - 1][y - 1][0]);
			if ((x - y) & 1) dp[x][y][0] = min(dp[x][y][0], x - dp[x - 1][y][0]);
			if (x - y >= 2) dp[x][y][0] = min(dp[x][y][0], x - dp[x - 1][y + 1][0]);
			dp[x][y][1] = INF;
			if (y) {
				dp[x][y][1] = dp[x][y][0];
				dp[x][y][0] = min(dp[x][y][0], x - dp[x][y][1]);
			}
		}
	}
}

void solve() {
  cin >> n >> s;
  int x = 0, y = 0;
  rep(i, 0, n - 1) if (s[i] == '0') x++;
  rep(i, 0, n / 2 - 1) if (s[i] != s[n - 1 - i]) y++;
  int ans = dp[x][y][0];
  if (ans * 2 == x) cout << "DRAW" << endl;
  else if (ans * 2 < x) cout << "ALICE" << endl;
  else cout << "BOB" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1000);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
} 