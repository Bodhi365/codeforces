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
  sort(a + 1, a + n + 1);
  int num = unique(a + 1, a + n + 1) - a - 1;
  int ans = 0;
  for (int l = 1, r = 1; r <= num; r++) {
  	while (a[r] - a[l] > n - 1) l++;
  	ans = max(ans, r + 1 - l);
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