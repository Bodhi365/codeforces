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
int dp[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  int mx = -1;
  int sum = accumulate(a + 1, a + n + 1, 0);
  rep(i, 1, n) {
  	int now = a[i] == 1 ? -1 : 1;
  	dp[i] = max(0, dp[i - 1]) + now;
  	mx = max(mx, dp[i]);
  }
  cout << sum + mx << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}