#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, x;
int a[N];
int b[N], num;
bool check(int l, int r) {
  rep(i, l + 1, r) if (a[i - 1] > a[i]) return false;
  return true;
}
void solve() {
  cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  int l = n - x, r = 1 + x;
  if (l >= r) {
    cout << "YES" << endl;
    return;
  }
  bool res = check(l + 1, r - 1);
  if (!res) {
    cout << "NO" << endl;
    return;
  }
  rep(i, 1, n) b[i] = a[i];
  sort(b + 1, b + n + 1);
  rep(i, l + 1, r - 1) if (a[i] != b[i]) res = false;
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