#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k, p, m;
int a[N];
ll sum[N];

void solve() {
  cin >> n >> k >> p >> m;
  rep(i, 1, n) cin >> a[i];
  if (n <= k) {
    cout << m / a[p] << endl;
    return;
  }
  rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
  priority_queue<int, vector<int>, greater<int>> pq;
  int left = 0, x;
  rep(i, 1, n) {
    if (i == p) {
      x = sum[p] - left; 
      continue;
    }
    pq.push(a[i]);
    left += a[i];
    if (pq.size() == k) {
      int mn = pq.top();
      pq.pop();
      left -= mn;
    } 
  }
  if (x > m) {
    cout << 0 << endl;
  } else {
    ll ans = 1 + (m - x) / (sum[n] - left);
    cout << ans << endl;
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