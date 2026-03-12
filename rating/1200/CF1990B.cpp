#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int a[N];

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  rep(i, y, x) a[i] = 1;
  rep(i, x + 1, n) {
    int j = i - x;
    if (j & 1) a[i] = -1;
    else a[i] = 1;
  }
  per(i, y - 1, 1) {
    int j = y - i;
    if (j & 1) a[i] = -1;
    else a[i] = 1;
  }
  rep(i, 1, n) cout << a[i] << ' ';
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