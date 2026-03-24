#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  int x = 0;
  rep(i, 1, n) x ^= a[i];
  int y = 0;
  rep(i, 1, m) y |= b[i];
  if (n & 1) {
  	cout << x << ' ' << (x | y) << endl;
  } else {
  	cout << (x & (~y)) << ' ' << x << endl;
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