#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int cnt[N];
vector<int> g[N];
void add(int u, int v) { g[u].push_back(v); }
void init(int n) { rep(i, 1, n) g[i].clear(); }
void dfs(int u, int fu) {
  cnt[u] = 0;
  for (int v : g[u]) {
    if (v == fu) continue;
    dfs(v, u);
    cnt[u] += cnt[v];
  }
  if (!cnt[u]) cnt[u] = 1;
}
void solve() {
  cin >> n;
  init(n);
  rep(i, 2, n) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    ll ans = 1ll * cnt[u] * cnt[v];
    cout << ans << endl;
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