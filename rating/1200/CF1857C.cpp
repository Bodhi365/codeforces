#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1e6 + 5;

int n, m;
int a[N], b[N];

void solve() {
  cin >> n;
  m = (n - 1) * n / 2;
  rep(i, 1, m) cin >> b[i];
  sort(b + 1, b + m + 1);
  int j = 1;
  rep(i, 1, n - 1) {
    a[i] = b[j];
    j += n - i;
  }
  a[n] = a[n - 1];
  rep(i, 1, n) cout << a[i] << ' ';
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