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
  sort(a + 1, a + n + 1);
  if (n == 2) {
  	rep(i, 1, n) cout << a[i] << ' ';
  	cout << endl;
  	return;
  }
  int mn = 1;
  rep(i, 2, n - 1) {
  	if (a[i + 1] - a[i] < a[mn + 1] - a[mn]) {
  		mn = i;
  	}
  }
  rep(i, mn + 1, n) cout << a[i] << ' ';
  rep(i, 1, mn) cout << a[i] << ' ';
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