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
int b[N];
void solve() {
  cin >> n;
  if (!(n & 1)) {
  	cout << "No" <<endl;
  	return;
  }
  rep(i, 1, n) a[i] = i, b[i] = 2 * n + 1 - i;
  // 1 .. (n + 1) / 2 .. n // d = (n - 1) / 2
  int d = (n - 1) / 2;
  for (int l = 1, r = 1 + d; l < r; l++, r--) {
  	swap(a[l], a[r]);
  }
  for (int l = 2 + d, r = n; l < r; l++, r--) {
  	swap(a[l], a[r]);
  }
  cout << "Yes" << endl;
  rep(i, 1, n) cout << a[i] << ' ' << b[i] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}