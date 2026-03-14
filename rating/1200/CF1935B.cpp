#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], cnt[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 0, n) cnt[i] = 0;
  rep(i, 1, n) cnt[a[i]]++;
  int x = n;
  rep(i, 0, n - 1) {
    if (!cnt[i]) {
      x = i;
      break;
    } else if (cnt[i] == 1) {
      cout << -1 << endl;
      return;
    }
  }
  if (x == 0) {
    cout << 2 << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 2 << ' ' << n << endl;
    return;
  }
  set<int> st;
  vector<pii> ans;
  int l = 1;
  rep(i, 1, n) {
    if (a[i] < x) st.insert(a[i]);
    if (st.size() == x) {
      st.clear();
      ans.push_back(pii(l, i));
      l = i + 1;
    }
  }
  ans.back().second = n;
  if (ans.size() <= 1) cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << ' ' << p.second << endl;
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