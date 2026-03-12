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
int cnt[128];

void solve() {
  cin >> n;
  cin >> s;
  memset(cnt, 0, sizeof(cnt));
  for (auto c : s) cnt[c]++;
  int mx = *max_element(cnt, cnt + 128);
  int ans = max(mx * 2 - n, n & 1);
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