#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  int l = -1, r = -1, ans = 0;
  rep(i, 1, n) {
    if (a[i] >= l && a[i] <= r) r = a[i] + 1;
    else ans++, l = a[i] + 1, r = a[i] + 1; 
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