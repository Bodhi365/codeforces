#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int k[N];
ll x[N];

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> k[i];
  ll tot = 1, sum = 0;
  rep(i, 1, n) tot = lcm(tot, k[i]);
  rep(i, 1, n) x[i] = tot / k[i], sum += x[i];
  if (sum >= tot) cout << -1 << endl;
  else {
    rep(i, 1, n) cout << x[i] << ' ';
    cout << endl;
  }
  return;
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}