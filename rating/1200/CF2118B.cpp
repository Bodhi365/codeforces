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
  cout << n * 2 - 2 << endl;
  cout << 1 << ' ' << 2 << ' ' << n << endl;
  cout << n << ' ' << 1 << ' ' << n << endl;
  rep(i, 2, n - 1) {
    cout << i << ' ' << 1 << ' ' << i << endl;
    cout << i << ' ' << i + 1 << ' ' << n << endl;
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