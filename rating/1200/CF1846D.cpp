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

void solve() {
  int d, h;
  cin >> n >> d >> h;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  rep(i, 1, n - 1) a[i] = min(a[i + 1] - a[i], h);
  a[n] = h;
  double sum = 0, x = 0.5 * d * h;
  rep(i, 1, n) {
    double y = h - a[i];
    double ratio = 1.0 - y * y / h / h;
    double now = x * ratio;
    sum += now;
  }
  cout << fixed << setprecision(8) << sum << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}