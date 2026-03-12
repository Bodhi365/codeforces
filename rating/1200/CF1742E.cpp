#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll a[N], mx[N];
ll sum[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
  rep(i, 1, n) mx[i] = max(mx[i - 1], a[i]);
  while (m--) {
    ll k;
    cin >> k;
    int i = upper_bound(mx + 1, mx + n + 1, k) - mx;
    cout << sum[i - 1] << ' ';
  }
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