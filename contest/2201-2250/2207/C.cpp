#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2005;
const int K = 2.1e6 + 5;
int n, m;
ll a[N];
ll b[N], cnt;
ll area[K];
int head[K], num;
int ver[K], Next[K], tot;
void add(int u, int v) {
  ++tot;
  ver[tot] = v;
  Next[tot] = head[u];
  head[u] = tot;
}
int rt;
struct Node {
  ll l, r, id;
};
ll mx[K], mn[K];
void dfs(int u) {
  mx[u] = mn[u] = 0;
  for (int i = head[u]; i; i = Next[i]) {
    int v = ver[i];
    dfs(v);
    mn[u] = max(mn[u], mx[v]);
    if (mx[u] < mn[u]) swap(mx[u], mn[u]);
    mn[u] = max(mn[u], mn[v]);
    if (mx[u] < mn[u]) swap(mx[u], mn[u]);
  }
  mx[u] += area[u];
}
void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) b[i] = a[i] = m - a[i];
  b[n + 1] = 0;
  sort(b + 1, b + n + 2);
  cnt = unique(b + 1, b + n + 2) - b - 1;
  vector<Node> pre;
  per(i, cnt, 1) {
    vector<Node> now;
    ll x = b[i];
    int l = 1;
    while (l <= n) {
      if (a[l] < x) {
        l++;
        continue;
      }
      int r = l + 1;
      while (r <= n && a[r] >= x) r++;
      ++num;
      head[num] = 0;
      now.push_back(Node{l, r - 1, num});
      l = r;
    }
    int len = pre.size();
    int j = 0;
    for (auto& p : now) {
      while (j < len && pre[j].r <= p.r) {
        add(p.id, pre[j].id);
        area[pre[j].id] = (b[i + 1] - b[i]) * (pre[j].r - pre[j].l + 1);
        j++;
      }
    }
    pre.clear();
    swap(pre, now);
  }
  rt = num;
  dfs(rt);
  cout << mx[rt] + mn[rt] << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}