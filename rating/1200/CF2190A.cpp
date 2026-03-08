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

void solve() {
  cin >> n;
  cin >> s;
  int cnt[2] = { 0 };
  for (char c : s) cnt[c - '0']++;
  vector<int> ans;
  rep(i, 0, n - 1) {
    if (i < cnt[0] && s[i] == '1') ans.push_back(i + 1);
    if (i >= cnt[0] && s[i] == '0') ans.push_back(i + 1);
  }
  if (ans.empty()) cout << "Bob" << endl;
  else {
    cout << "Alice" << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
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