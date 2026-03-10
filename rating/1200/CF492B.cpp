#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, l;
int a[N];

void solve() {
  cin >> n >> l;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  double ans = max(a[1], l - a[n]);
  rep(i, 1, n - 1) {
    double d = (a[i + 1] - a[i]) / 2.0;
    ans = max(ans, d);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}