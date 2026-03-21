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
bool check() {
  rep(i, 1, n - 1) if (a[i] > a[i + 1]) return false;
  return true;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  for (int i = (n & 1) + 1; i <= n; i += 2) {
    if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
  }
  bool res = check();
  cout << (res ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}