#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, l, r, k;
ll lowbit(ll x) { return x & -x; }
void solve() {
  cin >> n >> l >> r >> k;
  if (n & 1) cout << l << endl;
  else if (n == 2) cout << -1 << endl;
  else {
  	ll x = l + lowbit(l);
  	while (x != lowbit(x)) x += lowbit(x);
  	if (x > r) cout << -1 << endl;
  	else if (k >= n - 1) cout << x << endl;
  	else cout << l << endl;
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