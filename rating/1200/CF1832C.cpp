#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 3e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  vector<int> ans;
  rep(i, 1, n) {
    if (ans.size() && ans.back() == a[i]) continue;
    if (ans.size() < 2) ans.push_back(a[i]);
    else {
      int len = ans.size();
      int x = ans[len - 2], y = ans[len - 1];
      bool inc = x <= y && y <= a[i];
      bool dec = x >= y && y >= a[i];
      if (inc || dec) ans[len - 1] = a[i];
      else ans.push_back(a[i]);
    }
  }
  cout << ans.size() << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}