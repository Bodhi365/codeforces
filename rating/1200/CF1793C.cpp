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
int pos[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) pos[a[i]] = i;
  int l = 1, r = n, mn = 1, mx = n;
  while (l < r) {
    if (a[l] == mn) l++, mn++;
    else if (a[l] == mx) l++, mx--;
    else if (a[r] == mn) r--, mn++;
    else if (a[r] == mx) r--, mx--;
    else {
      cout << l << ' ' << r << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}