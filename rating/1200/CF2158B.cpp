#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 4e5 + 5;

int n, m;
int cnt[N];

void solve() {
  cin >> n;
  rep(i, 1, n * 2) cnt[i] = 0;
  rep(i, 1, n * 2) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int x = 0, y = 0;
  rep(i, 1, n * 2) {
    if (!cnt[i]) continue;
    else if (cnt[i] & 1) x++;
    else y++;
  }
  if (!x && (y & 1) != (n & 1)) y--;
  cout << x + y * 2 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}