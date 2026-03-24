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
int ans[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  per(i, n, 1) {
    int x = 0, y = 0;
    rep(j, i + 1, n) {
      if (a[j] > a[i]) x++;
      if (a[j] < a[i]) y++;
    }
    ans[i] = max(x, y);
  }
  rep(i, 1, n) cout << ans[i] << ' ';
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