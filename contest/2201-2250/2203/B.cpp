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
  ll x;
  cin >> x;
  if (x < 10) {
    cout << 0 << endl;
    return;
  }
  vector<int> a;
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  int len = a.size();
  sort(a.begin(), a.end() - 1);
  int l = 0, sum = a[len - 1];
  while (l < len - 1 && sum + a[l] < 10) sum += a[l++];
  int ans = len - l - 1;
  l = 0, sum = 1;
  while (l < len - 1 && sum + a[l] < 10) sum += a[l++];
  ans = min(ans, len - l);
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