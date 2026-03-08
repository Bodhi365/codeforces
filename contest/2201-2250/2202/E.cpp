#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 3e5 + 5;
const int MOD = 998244353;

int n, m;
string s;
ll dp[N][2];
ll sum[N][2][2];

void solve() {
  cin >> n;
  cin >> s;
  s = ' ' + s;
  int cnt = 0;
  rep(i, 1, n) {
    // dp[i][0] = \sum dp[j][0]
    int now = s[i] == '(' ? 0 : 1;
    if (!now) cnt++;
    else cnt--;
    dp[i][0] = (1 + sum[i - 1][now][0] + sum[i - 1][now ^ 1][1]) % MOD;
    dp[i][1] = 0;
    if (now || cnt >= 2) {
      dp[i][1] = (1 + sum[i - 1][now][1] + sum[i - 1][now ^ 1][0]) % MOD;
    } else {
      dp[i][1] = 0;
    }
    rep(j, 0, 1) rep(k, 0, 1) sum[i][j][k] = sum[i - 1][j][k];
    sum[i][now][0] = (sum[i][now][0] + dp[i][0]) % MOD;
    sum[i][now][1] = (sum[i][now][1] + dp[i][1]) % MOD;
    if (now && cnt < 2) sum[i][0][1] = 0;
  }
  cout << (sum[n][0][0] + sum[n][1][0]) % MOD << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}