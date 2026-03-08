#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, k;
int a[N];

void solve() {
  cin >> n >> m >> k;
  int c[2] = {0, 1};
  if (n < m) swap(c[0], c[1]), swap(n, m);
  if (abs(n - m) > k || n < k) {
    cout << -1 << endl;
    return;
  }
  int x = k - (n - m);
  int y = k;
  int z = n - k; // n - k, m - x
  rep(i, 1, x) cout << c[1];
  rep(i, 1, z) cout << c[0] << c[1];
  rep(i, 1, y) cout << c[0];
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