#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 505;

int n, m;
char a[N][N], b[N][N];
bool check_row(int i) {
  int sum = 0;
  rep(j, 1, m) sum += a[i][j] - b[i][j];
  return sum % 3 == 0;
}
bool check_col(int j) {
  int sum = 0;
  rep(i, 1, n) sum += a[i][j] - b[i][j];
  return sum % 3 == 0;
}
bool check_row() {
  rep(i, 1, n) if (!check_row(i)) return false;
  return true;
}
bool check_col() {
  rep(i, 1, m) if (!check_col(i)) return false;
  return true;
}
void solve() {
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 1, n) rep(j, 1, m) cin >> b[i][j];
  bool res = check_row() && check_col();
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