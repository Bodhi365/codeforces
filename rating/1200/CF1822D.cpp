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
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  if (n & 1) {
    cout << -1 << endl;
    return;
  }
  int a = 1, b = n;
  rep(i, 1, n) {
    if (i & 1) {
      cout << b << ' ';
      b -= 2;
    } else {
      cout << a << ' ';
      a += 2;
    }
  }
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