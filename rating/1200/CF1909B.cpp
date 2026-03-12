#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll a[N];

ll lowbit(ll x) {
  return x & -x;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  ll k = 1;
  rep(i, 0, 59) {
    int cnt[2] = { 0 };
    rep(j, 1, n) cnt[a[j] >> i & 1]++;
    if (cnt[0] && cnt[1]) {
      k = 1ll << (i + 1);
      break;
    }
  }
  cout << k << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}