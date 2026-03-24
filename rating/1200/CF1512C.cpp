#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, a, b;
string s;

void solve() {
  cin >> a >> b;
  cin >> s;
  n = a + b;
  bool f2 = (a & 1) && (b & 1);
  bool f0 = (a & 1) && s[n / 2] == '1';
  bool f1 = (b & 1) && s[n / 2] == '0';
  if (f0 || f1 || f2) {
  	cout << -1 << endl;
  	return;
  }
  if (a & 1) s[n / 2] = '0', a--;
  if (b & 1) s[n / 2] = '1', b--;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] != s[j]) {
      if (s[i] != '?' && s[j] != '?') {
        cout << -1 << endl;
        return;
      } else if (s[i] == '?')
        s[i] = s[j];
      else
        s[j] = s[i];
    }
    if (s[i] == '0') a -= 2;
    if (s[i] == '1') b -= 2;
  }
  if (a < 0 || b < 0) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] != '?') continue;
    if (a >= 2) {
      s[i] = s[j] = '0', a -= 2;
    } else {
      s[i] = s[j] = '1', b -= 2;
    }
  }
  cout << s << endl;
  return;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}