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
int cnt[128], cnt2[128];

void solve() {
  cin >> n;
  cin >> s;
  if (n & 1) {
    cout << -1 << endl;
    return;
  }
  rep(i, 'a', 'z') cnt[i] = cnt2[i] = 0;
  for (char c : s) cnt[c]++;
  rep(i, 'a', 'z') if (cnt[i] * 2 > n) {
    cout << -1 << endl;
    return;
  }
  int tot = 0, mx = 0;
  rep(i, 0, n / 2 - 1) {
    int j = n - 1 - i;
    if (s[i] == s[j]) {
      mx = max(mx, ++cnt2[s[i]]);
      tot++;
    }
  }
  int ans = max((tot + 1) / 2, mx);
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}