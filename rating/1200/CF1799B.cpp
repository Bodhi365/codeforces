#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], id[N];
bool cmp(int i, int j) { return a[i] < a[j]; }
bool equal() {
  int mn = *min_element(a + 1, a + n + 1);
  int mx = *max_element(a + 1, a + n + 1);
  return mn == mx;
}
bool check_1() {
  int mn = *min_element(a + 1, a + n + 1);
  return mn == 1;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  if (equal()) {
    cout << 0 << endl;
    return;
  }
  if (check_1()) {
    cout << -1 << endl;
    return;
  }
  rep(i, 1, n) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  vector<pii> ans;
  while (a[id[1]] != 2) {
    int i = id[n], j = id[1];
    if (a[i] == a[j]) break;
    while (a[i] > a[j]) {
      a[i] = (a[i] + a[j] - 1) / a[j];
      ans.push_back(pii(i, j));
    }
    sort(id + 1, id + n + 1, cmp);
  }
  if (a[id[1]] != a[id[n]]) {
    int j = id[1];
    rep(k, 2, n) {
      int i = id[k];
      while (a[i] != 2) {
        a[i] = (a[i] + 1) / 2;
        ans.push_back(pii(i, j));
      }
    }
  } 
  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << endl;
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