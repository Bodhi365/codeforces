#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int c[N], p[N];
double dp[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> c[i] >> p[i];
  dp[n + 1] = 0;
  per(i, n, 1) {
    double x = dp[i + 1] * (1.0 - p[i] / 100.0) + c[i]; 
    dp[i] = max(dp[i + 1], x);
  }
  cout << fixed << setprecision(10) << dp[1] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}