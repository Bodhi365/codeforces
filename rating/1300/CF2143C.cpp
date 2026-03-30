#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
struct Edge {
  int v, x, y;
};
vector<Edge> g[N];
int deg[N];
int p[N];
bool vis[N];

void solve() {
  cin >> n;
  rep(i, 1, n) g[i].clear(), deg[i] = 0, vis[i] = 0, p[i] = 0;
  rep(i, 2, n) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    g[u].push_back({v, x, y});
    g[v].push_back({u, y, x});
    deg[u]++, deg[v]++;
  }
  int mn = 1, mx = n;
  queue<int> q;
  rep(i, 1, n) if (deg[i] == 1) q.push(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto e : g[u]) {
      int v = e.v, x = e.x, y = e.y;
      if (vis[v]) continue;
      if (x > y) p[u] = mx--;
      else p[u] = mn++;
      deg[v]--;
      if (deg[v] == 1) q.push(v);
    }
    if (!p[u]) p[u] = mn++;
  }
  rep(i, 1, n) cout << p[i] << ' ';
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