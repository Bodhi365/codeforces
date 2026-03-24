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
  vector<int> a, b;
  int x = -1;
  rep(i, 1, n) {
  	int y;
  	cin >> y;
  	if (i == 1) {
  		x = y;
  		continue;
  	}
  	if (y == x) a.push_back(i);
  	else b.push_back(i);
  }
  if (b.empty()) {
  	cout << "NO" << endl;
  	return;
  }
  cout << "YES" << endl;
  for (int y : b) cout << 1 << ' ' << y << endl;
  x = b[0];
	for (int y : a) cout << x << ' ' << y << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}