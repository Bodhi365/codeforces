#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  map<int, int> cnt;
  rep(i, 1, n) cnt[a[i]]++;
  int x0 = 0, y0 = 0, ans = 0;
  for (auto p : cnt) {
    int x = p.first, y = p.second;
    if (x != x0 + 1) x0 = y0 = 0;
    ans += max(0, y - y0);
    x0 = x, y0 = y; 
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