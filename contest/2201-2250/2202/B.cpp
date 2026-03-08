#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
string s;
bool dp[N][2][2];  // dp[i][char][nxt]
void solve() {
  cin >> n;
  cin >> s;
  s = ' ' + s;
  rep(i, 1, n) rep(j, 0, 1) rep(k, 0, 1) dp[i][j][k] = 0;
  if (n & 1) {
    if (s[1] != 'b') dp[1][0][0] = 1;
  } else {
    if (s[1] != 'b') dp[1][0][1] = 1;
    if (s[1] != 'a') dp[1][1][0] = 1;
  }
  rep(i, 2, n) {
    rep(j1, 0, 1) {
      if (j1 == 0 && s[i] != 'a' && s[i] != '?') continue;
      if (j1 == 1 && s[i] != 'b' && s[i] != '?') continue;
      rep(j2, 0, 1) rep(k, 0, 1) {
        if (j1 == j2 && j1 != k) continue;
        if (!dp[i - 1][j2][k]) continue;
        if (j1 == j2) dp[i][j1][k ^ 1] = 1;
        else dp[i][j1][k] = 1;
      }
    }
  }
  bool ans = 0;
  rep(j, 0, 1) rep(k, 0, 1) ans |= dp[n][j][k];
  cout << (ans ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}