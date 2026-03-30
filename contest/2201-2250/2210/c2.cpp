#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5e4 + 5;
const int K = 18;
const int INF = 1e9;

int n, m;
ll a[N], b[N];
ll c[N];
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll d = gcd(a, b);
	return a / d * b;
}
ll primes[N], tot;
void init(int n) {
  primes[1] = 1;
  tot = 1;
  for (int i = 2; i <= 1000; i++) {
    bool f = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f = false;
        break;
      }
    }
    if (f) primes[++tot] = i;
  }
}
ll dp[N][K + 1];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) {
  	int x = 1, y = 1;
  	if (i > 1) x = gcd(a[i], a[i - 1]);
  	if (i < n) y = gcd(a[i], a[i + 1]);
  	c[i] = lcm(x, y);
  }
  rep(j, 0, K) dp[1][j] = -INF;
  dp[1][0] = 0; // unchange
  rep(j, 1, K) {
    ll x = c[1] * primes[j];
    if (x > b[1]) break;
    if (x == a[1]) continue;
    dp[1][j] = 1;
  }
  rep(i, 2, n) {
    ll d0 = gcd(a[i - 1], a[i]);
    rep(j, 0, K) dp[i][j] = -INF;
    // unchange
    rep(k, 0, K) {
      ll y = k ? c[i - 1] * primes[k] : a[i - 1];
      ll d = gcd(y, a[i]);
      if (d == d0) dp[i][0] = max(dp[i][0], dp[i - 1][k]);
    }
    rep(j, 1, K) {
      ll x = c[i] * primes[j];
      if (x > b[i]) break;
      if (x == a[i]) continue;
      rep(k, 0, K) {
        ll y = k ? c[i - 1] * primes[k] : a[i - 1];
        ll d = gcd(y, x);
        if (d == d0) dp[i][j] = max(dp[i][j], 1 + dp[i - 1][k]);
      }
    }
  }
  ll ans = 0;
  rep(j, 0, K) ans = max(ans, dp[n][j]);
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1000);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}