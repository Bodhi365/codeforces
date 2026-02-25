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
  ll x, y;
  cin >> x >> y;
  if (x == y) {
    cout << -1 << endl;
    return;
  }
  if (x < y) swap(x, y); // make x > y
  ll z = 1;
  while (z <= x) z <<= 1;
  cout << z - x << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}