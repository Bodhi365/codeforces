#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int x[N], y[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> x[i];
  rep(i, 1, n) cin >> y[i];
  rep(i, 1, n) x[i] = y[i] - x[i];
  sort(x + 1, x + n + 1);
  int cnt = 0;
  for (int l = 1, r = n; l < r; l++) {
  	if (x[l] + x[r] >= 0) cnt++, r--; 
  }
  cout << cnt << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}