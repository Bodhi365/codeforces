#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, m, k;

void solve() {
  cin >> n >> m >> k;
  ll mx = n * (n - 1) / 2;
  if (m < n - 1 || m > mx) {
    cout << "NO" << endl;
  } else if (n == 1 ) {
    cout << (k >= 2 ? "YES" : "NO") << endl;
  } else if (m == mx) {
    cout << (k >= 3 ? "YES" : "NO") << endl;
  } else {
    cout << (k >= 4 ? "YES" : "NO") << endl;
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