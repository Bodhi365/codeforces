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
  bool zero = 0;
  rep(i, 1, n) if (!a[i]) zero = 1;
  if (!zero) {
    cout << 1 << endl;
    cout << 1 << ' ' << n << endl;
  } else if (a[1] != 0) {
    cout << 2 << endl;
    cout << 2 << ' ' << n << endl;
    cout << 1 << ' ' << 2 << endl;
  } else if (a[n] != 0) {
    cout << 2 << endl;
    cout << 1 << ' ' << n - 1 << endl;
    cout << 1 << ' ' << 2 << endl;
  } else {
    cout << 3 << endl;
    cout << 3 << ' ' << n << endl;
    cout << 1 << ' ' << 2 << endl;
    cout << 1 << ' ' << 2 << endl;
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