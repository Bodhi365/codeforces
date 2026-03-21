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

int f(string& s, string& t) {
  int res = 0;
  rep(i, 0, n - 1) res += s[i] != t[i];
  return res;
}
void solve() {
  cin >> n;
  string s;
  string t;
  cin >> s >> t;
  int x = f(s, t);
  if (x & 1) x = x * 2 - 1;
  else x = x * 2;
  reverse(s.begin(), s.end());
  int y = max(1, f(s, t));
  if (y & 1) y = y * 2;
  else y = y * 2 - 1;
  cout << min(x, y) << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}