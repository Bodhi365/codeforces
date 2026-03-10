#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a, b, c, d;

void solve() {
  cin >> a >> b >> c >> d;
  if (!a) cout << 1 << endl;
  else {
    int ans = a;
    int x = min(b, c), y = abs(b - c) + d;
    ans += x * 2;
    ans += min(a + 1, y);
    cout << ans << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}