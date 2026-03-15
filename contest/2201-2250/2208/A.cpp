#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int cnt[N];

void solve() {
  cin >> n;
  rep(i, 1, n * n) cnt[i] = 0;
  rep(i, 1, n) rep(j, 1, n) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int mx = *max_element(cnt + 1, cnt + n * n + 1);
  if (mx > n * (n - 1)) cout << "NO" << endl;
  else cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}