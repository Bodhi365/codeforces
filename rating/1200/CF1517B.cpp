#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 105;
const int INF = 1e9;

int n, m;
int a[N][N];
int b[N][N];
int mn[N];
int id[N];
bool cmp(int i, int j) { return mn[i] < mn[j]; }

void solve() {
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 1, m) mn[i] = INF, id[i] = i;
  rep(i, 1, n) {
  	sort(id + 1, id + m + 1, cmp);
  	sort(a[i] + 1, a[i] + m + 1, greater<int>());
  	rep(j, 1, m) b[i][id[j]] = a[i][j], mn[id[j]] = min(mn[id[j]], a[i][j]);
  }
  rep(i, 1, n) rep(j, 1, m) cout << b[i][j] << " \n"[j == m];
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}