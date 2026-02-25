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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool check(int k) {
  int d = 0;
  rep(i, 1, k) {
    for (int j = i + k; j <= n; j += k) {
      int now = abs(a[j] - a[i]);
      d = gcd(d, now);
      if (d == 1) return false;
    }
  }
  return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i) continue;
    if (check(i)) ans++;
    int j = n / i;
    if (j != i && check(j)) ans++;
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