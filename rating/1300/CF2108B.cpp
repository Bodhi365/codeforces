#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x;

void solve() {
  cin >> n >> x;
  int a = __builtin_popcount(x);
  int b = n - a;
  if (b <= 0) cout << x << endl;
  else if ((b & 1) == 0) cout << x + b << endl;
  else if (x == 0) {
    if (b == 1) cout << -1 << endl;
    else cout << x + b + 3 << endl;
  } else if (x == 1) {
    cout << x + b + 3 << endl;
  } else cout << x + b + 1 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}