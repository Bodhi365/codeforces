#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 8005;

int n, m;
int a[N][N], b[N][N], c[N][N];
int cnt[N], id[N];
vector<int> e[N];
bool cmp(int x, int y) {
  return cnt[x] < cnt[y];
}
int f[N];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) f[fy] = fx;
}
bool check() {
  rep(i, 1, n) f[i] = i;
  rep(i, 1, n) rep(j, 1, n) {
    if (c[i][j]) merge(i, j);
  }
  int cnt = 0;
  rep(i, 1, n) if (f[i] == i) cnt++;
  return cnt == 1;
}
void solve() {
  cin >> n;
  rep(i, 1, n) rep(j, 1, n) {
    char x;
    cin >> x;
    a[i][j] = x - '0';
    b[i][j] = c[i][j] = 0;
  }
  rep(i, 1, n) {
    cnt[i] = 0;
    rep(j, 1, n) cnt[i] += a[i][j];
  }
  rep(i, 1, n) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  int tot = 0;
  rep(i, 1, n) {
    int u = id[i];
    e[u].clear();
    e[u].push_back(u);
    b[u][u] = 1;
    per(j, i - 1, 1) {
      int v = id[j];
      if (!a[u][v] || b[u][v]) continue;
      c[u][v] = 1, tot++;
      for (int x : e[v]) {
        if (b[u][x]) {
          cout << "NO" << endl;
          return;
        }
        b[u][x] = 1;
        e[u].push_back(x);
      }
    }
    rep(i, 1, n) if (a[u][i] != b[u][i]) {
      cout << "NO" << endl;
      return;
    }
  }
  if (tot != n - 1 || !check()) {
    cout << "NO" << endl;
    return;
  } 
  cout << "YES" << endl;
  rep(i, 1, n) rep(j, 1, n) {
    if (i == j || !c[i][j]) continue;
    cout << i << ' ' << j << endl;
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