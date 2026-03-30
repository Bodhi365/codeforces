#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 205;

int n, m;
int deg[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) deg[i] = 0;
  rep(i, 1, m) {
  	int u, v;
  	cin >> u >> v;
  	deg[u]++, deg[v]++;
  }
  int xy = 0;
  rep(i, 1, n) if (deg[i] == 1) xy++;
  int x = n - xy - 1;
  int y = xy / x;
  cout << x << ' ' << y << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}