#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  cin >> m;
  rep(i, 1, m) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int i = 1, j = 1, ans = 0;
  while (i <= n && j <= m) {
    if (abs(a[i] - b[j]) > 1) {
      if (a[i] < b[j]) i++;
      else j++;
    } else {
      ans++;
      i++, j++;
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}