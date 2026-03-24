#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n;
ll x[N], sum[N], num = 30;
void init() {
	rep(i, 1, num) x[i] = (1ll << i) - 1;
	rep(i, 1, num) sum[i] = sum[i - 1] + x[i] * (x[i] + 1) / 2;
}
void solve() {
  cin >> n;
  int ans = upper_bound(sum + 1, sum + num + 1, n) - sum - 1;
  cout << ans << endl;
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