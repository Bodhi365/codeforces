#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k;
int a[N];

void solve() {
  cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (k == 0) {
  	if (a[1] == 1) cout << -1 << endl;
  	else  cout << a[1] - 1 << endl;
  } else if (k == n) {
    cout << a[n] << endl;
  } else {
    int x = a[k], y = a[k + 1];
    if (x == y)
      cout << -1 << endl;
    else
      cout << x << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}