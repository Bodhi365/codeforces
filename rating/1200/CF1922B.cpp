#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 3e5 + 5;

int n, m;
int cnt[N];
ll c[N][4];
void init(int n) {
  rep(i, 0, n) c[i][0] = 1;
  rep(j, 1, 3) {
    rep(i, j, n) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
}
void solve() {
  cin >> n;
  rep(i, 0, n) cnt[i] = 0;
  rep(i, 1, n) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int sum = 0;
  ll ans = 0;
  rep(i, 0, n) {
    int x = cnt[i];
    ans += c[x][3] + c[x][2] * sum;
    sum += x;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(3e5);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}