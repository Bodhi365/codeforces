#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x;
int a[N];

void solve() {
  cin >> n >> x;
  bool fail = false;
  int y = 0;
  rep(i, 0, n - 1) {
    if (!fail && (i & x) != i) fail = 1;
    if (fail) a[i] = x;
    else a[i] = i;
    y |= a[i];
  }
  if (y != x) a[n - 1] = x;
  rep(i, 0, n - 1) cout << a[i] << ' ';
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