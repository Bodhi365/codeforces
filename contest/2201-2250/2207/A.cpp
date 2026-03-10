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
int get_mn(string s) {
  rep(i, 1, n - 2) {
    if (s[i - 1] == '1' && s[i + 1] == '1') s[i] = '0';
  }
  int cnt = 0;
  rep(i, 0, n - 1) if (s[i] == '1') cnt++;
  return cnt;
}
void solve(string s) {
  rep(i, 1, n - 2) {
    if (s[i - 1] == '1' && s[i + 1] == '1') s[i] = '1';
  }
  int mx = 0;
  rep(i, 0, n - 1) if (s[i] == '1') mx++;
  rep(i, 1, n - 2) {
    if (s[i - 1] == '1' && s[i + 1] == '1') s[i] = '0';
  }
  int mn = 0;
  rep(i, 0, n - 1) if (s[i] == '1') mn++;
  cout << mn << ' ' << mx << endl;
}
void solve() {
  cin >> n;
  string s;
  cin >> s;
  solve(s);
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}