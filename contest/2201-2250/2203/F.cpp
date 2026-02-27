#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5e6 + 5;

int n, m;
map<int, ll> sz;
map<int, ll> g[N], h[N];  // 左子树大小 : 个数， 右子树大小 ： 个数
ll d[N];
void dfs_sz(int n) {
  if (!n) return;
  sz[n]++;
  int mid = (1 + n) / 2;
  dfs_sz(mid - 1);
  dfs_sz(n - mid);
}
void pushup(map<int, ll>& mp1, map<int, ll>& mp2) {
  for (auto p : mp2) mp1[p.first] += p.second;
}
void update(int n) {
  if (!n) return;
  int mid = (1 + n) / 2;
  int nl = mid - 1, nr = n - mid;
  g[n][nl + 1] = 1;
  h[n][nr + 1] = 1;
  pushup(g[n], g[nl]);
  pushup(g[n], g[nr]);
  pushup(h[n], h[nl]);
  pushup(h[n], h[nr]);
}
void solve() {
  cin >> n;
  dfs_sz(n);
  for (auto p : sz) update(p.first);
  map<int, ll> ans;
  for (auto p : sz) {
    int len = p.first;
    ll cnt = p.second;
    int mid = (1 + len) / 2;
    int nl = mid - 1, nr = len - mid;
    // 1 - mid - len
    // i (j, k) [j + 1, i] won't be found
    d[1] += cnt, d[mid] -= cnt;
    // i (k, j) [i, j - 1] won't be found
    d[1] += cnt, d[len - mid + 1] -= cnt;
    // k (i, j) 
    for (auto p1 : h[nl]) {
      for (auto p2 : g[nr]) {
        int x = p1.first + p2.first;
        ll y = p1.second * p2.second;
        ans[x] += y * cnt;
      }
    }
  }
  rep(i, 1, n) d[i] += d[i - 1];
  for (auto p : ans) {
    int x = p.first;
    ll y = p.second;
    d[x] += y;
  }
  reverse(d, d + n + 1);
  rep(i, 0, n) cout << d[i] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}