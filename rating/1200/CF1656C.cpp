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
bool check() {
  if (n <= 1) return true;
  if (a[1] == 0) return a[2] != 1;
  if (a[1] == 1) {
    for (int i = 2; i <= n; i++)
      if (a[i] - a[i - 1] == 1) return false;
    return true;
  }
  return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  bool res = check();
  cout << (res ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}