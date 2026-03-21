#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1e5 + 5;

int n, m;
int f[N];
int a[N];

void init(int n) {
  rep(i, 0, n) f[i] = -1;
  // f[i] must exist, which can be proven.
  int mx = sqrt(n * 2);
  f[0] = 0;
  rep(i, 1, n) {
    if (!f[i - 1]) {
      // i = x^2 + 1
      // j = 2*x
      int x = round(sqrt(i - 1));
      f[i] = x * 2;
    } else {
      f[i] = f[i - 1] - 1;
    }
  }
  return;
}
void dfs(int n) {
  if (n < 0) return;
  int p = f[n];
  reverse(a + p, a + n + 1);
  dfs(p - 1);
}
void solve() {
  cin >> n;
  rep(i, 0, n - 1) a[i] = i;
  dfs(n - 1);
  rep(i, 0, n - 1) cout << a[i] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1e5);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}