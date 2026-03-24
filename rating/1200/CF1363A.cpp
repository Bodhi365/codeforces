#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x, y, z;
int a[N];

void solve() {
  cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) a[i] = a[i] & 1;
  y = accumulate(a + 1, a + n + 1, 0);
  z = n - y;
  if (y && y % 2 == 0) y--;
  if (y + z < x || !y) {
  	cout << "NO" << endl;
  	return;
  } else {
  	if (!z && !(x & 1)) cout << "NO" << endl;
  	else cout << "YES" << endl;
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