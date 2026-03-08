#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 6e5 + 5;

int n, k;
int a[N];

void solve() {
  cin >> n >> k;
  if (k < n || k >= 2 * n) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  // x -> x
  // y -> y * 2 - 1
  // x + y = n, x + 2 * y = k + 1
  // y = k + 1 - n, x = n - y
  int y = k + 1 - n, x = n - y;
  if (y == 1) x++, y--;
  int num = 0;
  rep(i, 1, x) 
    a[++num] = i,
    a[++num] = i;
  if (y) {
    int id = x + 1;
    a[++num] = id++;
    a[++num] = id++;
    while (id <= n) {
      a[++num] = id, a[++num] = id - 2;
      ++id;
    }
    a[++num] = n - 1;
    a[++num] = n;
  }
  rep(i, 1, num) cout << a[i] << ' ';
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