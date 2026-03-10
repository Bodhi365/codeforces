#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, k;
ll a[N];

void solve() {
  cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  // make a[i] % (k + 1) == 0
  rep(i, 1, n) {
    int x = a[i] % (k + 1);
    a[i] += x * k;
  }
  rep(i, 1, n) cout << a[i] << ' ';
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