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

void solve() {
  ll x, y;
  cin >> x >> y;
  ll z = x + y;
  if (z < 0 || z % 3 || y > 0 && x < 2 * y || y < 0 && x < -4 * y) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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