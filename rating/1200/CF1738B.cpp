#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k;
ll a[N], sum[N];
bool check() {
  rep(i, n - k + 2, n) if (a[i] < a[i - 1]) return false;
  return true;
}
void solve() {
  cin >> n >> k;
  rep(i, n - k + 1, n) cin >> sum[i];
  rep(i, n - k + 2, n) a[i] = sum[i] - sum[i - 1];
  int x = sum[n - k + 1] / (n - k + 1);
  int r = sum[n - k + 1] % (n - k + 1);
  a[n - k + 1] = x;
  if (r > 0) a[n - k + 1]++;
  if (check())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}