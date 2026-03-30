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

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  set<ll> pos;
  pos.insert(0);
  ll sum = 0;
  rep(i, 1, n) {
  	if (i & 1) sum -= a[i];
  	else sum += a[i];
  	if (pos.count(sum)) {
  		cout << "YES" << endl;
  		return;
  	}
  	pos.insert(sum);
  }
  cout << "NO" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}