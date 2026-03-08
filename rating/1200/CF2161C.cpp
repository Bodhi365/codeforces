#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x;
int a[N], b[N];

void solve() {
  cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  int i = 1, j = n, k = 1;
  ll sum = 0, ans = 0;
  while (i <= j) {
    if (sum / x != (sum + a[j]) / x) ans += a[j], sum += a[j], b[k++] = a[j--];
    else sum += a[i], b[k++] = a[i++];
  }
  cout << ans << endl;
  rep(i, 1, n) cout << b[i] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}