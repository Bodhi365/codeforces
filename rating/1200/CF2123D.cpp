#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k;
char s[N];

void solve() {
  cin >> n >> k;
  rep(i, 1, n) cin >> s[i];
  int cnt = 0;
  rep(i, 1, n) if (s[i] == '1') cnt++;
  if (n < 2 * k || cnt <= k) cout << "Alice" << endl;
  else cout << "Bob" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}