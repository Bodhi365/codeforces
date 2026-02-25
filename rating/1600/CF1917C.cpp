#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k, m;
int a[N], b[N];

void solve() {
  cin >> n >> k >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, k) cin >> b[i];
  map<int, int> d;
  rep(i, 1, n) {
    if (a[i] > i) continue;
    vector<int> c;
    rep(j, 1, k) if (b[j] >= i) c.push_back(j);
    int num = c.size();
    if (!num) {
      if (a[i] == i) d[0]++;
      continue;
    }
    int x = i - a[i];
    int l, r;
    if (!x) {
      l = 0, r = c[0];
    } else if (x % num == 0) {
      l = x / num * k + (c[num - 1] - k);
      r = x / num * k + c[0];
    } else {
      l = x / num * k + c[x % num - 1];
      r = x / num * k + c[x % num];
    }
    if (l > m) continue;
    d[l]++, d[r]--;
  }
  int ans = (m - 1) / 2;
  int pre = 0;
  for (auto p : d) {
    int now = pre + p.second;
    int t = p.first;
    if (t >= m) break;
    ans = max(ans, (m - t - 1) / 2 + now);
    pre = now;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}