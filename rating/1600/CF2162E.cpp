#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], c[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) c[i] = 0, b[i] = 0;
  rep(i, 1, n) c[a[i]]++;
  int k = 0;
  rep(i, 1, n) if (!c[i]) b[++k] = i;
  int r = min(3, k);
  per(i, n, 1) {
    if (b[r] != a[i]) b[++r] = a[i];
    if (r >= 3) break;
  }
  reverse(b + k + 1, b + 4);
  rep(i, 1, m) cout << b[(i - 1) % 3 + 1] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}