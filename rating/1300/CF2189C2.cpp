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

int lowbit(int x) { return x & -x; }

void solve() {
  cin >> n;
  if (lowbit(n) == n) {
  	cout << -1 << endl;
  	return;
  }
  if (n & 1) {
  	a[1] = n - 1, a[n] = 1;
  	rep(i, 2, n - 1) a[i] = i ^ 1;
  	rep(i, 1, n) cout << a[i] << ' ';
  	cout << endl;
  } else {
  	a[1] = n, a[n] = 1;
  	rep(i, 2, n - 1) a[i] = i ^ 1;
  	int x = lowbit(n);
  	swap(a[1], a[x]);
  	rep(i, 1, n) cout << a[i] << ' ';
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