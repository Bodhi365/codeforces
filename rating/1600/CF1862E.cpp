#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, d;
int a[N];

void solve() {
  cin >> n >> m >> d;
  ll sum = 0, ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, 1, n) {
    int x;
    cin >> x;
    if (x <= 0) continue;
    pq.push(x);
    sum += x;
    while (pq.size() > m) {
      sum -= pq.top();
      pq.pop();
    }
    ans = max(ans, sum - 1ll * i * d);
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}