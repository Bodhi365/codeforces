#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll b[N];

void solve() {
  cin >> n;
  rep(i, 1, n + 2) cin >> b[i];
  sort(b + 1, b + n + 3);
  ll sum = accumulate(b + 1, b + n + 1, 0ll);
  if (sum == b[n + 1]) {
  	rep(i, 1, n) cout << b[i] << ' ';
  	cout << endl;
  } else {
  	sum += b[n + 1];
  	ll x = sum - b[n + 2];
  	int id = lower_bound(b + 1, b + n + 2, x) - b;
  	if (id > n + 1 || b[id] != x) cout << -1 << endl;
  	else {
  		rep(i, 1, n + 1) {
  			if (i == id) continue;
  			cout << b[i] << ' ';
  		}
  		cout << endl;
  	}
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